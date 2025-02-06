#include <iostream>
#include <stdlib.h>
//подключение glew для работы с шейдерами
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <string.h>
//подключение stb_image для получения картинки
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace std;

// GLuint prog;
//GLfloat angle = 0.0f; //угол поворота, но для чего он?

GLint success; //успешность линковки программы для шейдеров
GLchar infoLog[512]; //необходима для чтения данных из шейдера
GLfloat loc;
GLhandleARB v,f,p; //переменные для шейдеров и программы
float t; //переменная для времени в функции вращения
unsigned int tex1, tex2; //номера текстур

#define printOpenGLError() printOglError(FILE, LINE)

//проверка на работу glew
int printOglError(char *file, int line) //проверка на работу glew
{
    // Returns 1 if an OpenGL error occurred, 0 otherwise.
    GLenum glErr = glGetError();
    int retCode = 0;
    while (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s\n", file, line, gluErrorString(glErr));
        retCode = 1;
        glErr = glGetError();
    }
    return retCode;
}

//функция для чтения файла
char *textFileRead(char *fn) {
  FILE *fp;
  char *content = NULL;
  int count=0;
  if (fn != NULL) {
    fp = fopen(fn,"rt");
    if (fp != NULL) {
      fseek(fp, 0, SEEK_END);
      count = ftell(fp);
      rewind(fp);
      if (count > 0) {
        content = (char *)malloc(sizeof(char) * (count+1));
        count = fread(content,sizeof(char),count,fp);
        content[count] = '\0';
      }
      fclose(fp);
    }
  }
  return content;
}

//получение данных о шейдере
void printInfoLog(GLhandleARB obj)
{
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;
    glGetObjectParameterivARB(obj, GL_OBJECT_INFO_LOG_LENGTH_ARB, &infologLength);
    if (infologLength > 0)
    {
      infoLog = (char *)malloc(infologLength);
      glGetInfoLogARB(obj, infologLength, &charsWritten, infoLog);
      printf("%s\n",infoLog);
      free(infoLog);
    }
}

void setShaders() {
  char *vs = NULL,*fs = NULL;
  vs = textFileRead("Shader1.vert");
  fs = textFileRead("Shader1.frag");
  p = glCreateProgram(); //создание программы для шейдеров
  v = glCreateShader(GL_VERTEX_SHADER); //создание объекта вершинного шейдера
  f = glCreateShader(GL_FRAGMENT_SHADER); //создание объекта фрагментного шейдера
  glAttachShader(p,v); //присоединение вершинного шейдера к программе
  glAttachShader(p,f); //присоединение фрагментного шейдера к программе
  const char * vv = vs;
  const char * ff = fs;
  glShaderSource(v, 1, &vv, NULL); //загрузка кода вершинного шейдера
  glShaderSource(f, 1, &ff, NULL); //загрузка кода фрагментного шейдера
  free(vs);
  free(fs);
  glCompileShader(v); //компиляция вешинного шейдера
  glCompileShader(f); //компиляция фрагментного шейдера
  printInfoLog(v);
  printInfoLog(f);
  glLinkProgramARB(p); //линковка программы
  glGetProgramiv(p, GL_LINK_STATUS, &success); //получение статуса процесса линковки
  if (!success)
  {
    glGetProgramInfoLog(p, 512, NULL, infoLog);  //получение ошибок, если они есть
    cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
  glUseProgramObjectARB(p); //запуск программы для шейдеров
  loc = glGetUniformLocationARB(p,"time");
  glUseProgram(0);
}

//установка параметров текстуры
void Load_Texture(char *fileName, unsigned int *textureID)
{
    int width, height, cnt;
    unsigned char *data = stbi_load(fileName, &width, &height, &cnt, 0); //массив для текстуры
    glGenTextures(1, textureID); //выделение идентификатора текстуры
    glBindTexture(GL_TEXTURE_2D, *textureID); //установка текущей текстуры
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); //задача изображения для текстуры
    glBindTexture(GL_TEXTURE_2D, 0); //снятие текстуры со значения текущей
    stbi_image_free(data); //освобождение места загрузки текстуры
}

//загрузка текстур
void texture_upload()
{
    Load_Texture("cofe.png", &tex1); //соответсвие текстуры и идентификатора
    Load_Texture("paper.png", &tex2); //соответсвие текстуры и идентификатора
    glEnable(GL_DEPTH_TEST);
}

//отрисовка объекта с текстурой
void draw()
{
  //передача значений изображения в шейдеры
  glUseProgram(p); //запуск программы для шейдеров
  glActiveTexture(GL_TEXTURE0); //активация текстурного блока
  glBindTexture(GL_TEXTURE_2D, tex2); //выбор текущей текстуры
  glActiveTexture(GL_TEXTURE0 + 1);
  glBindTexture(GL_TEXTURE_2D, tex1);
  int q = glGetUniformLocation(p, "texA"); //передача текстуры в шейдер
  glUniform1i(q, 0); //связь uniform-переменной и текстурного блока
  q = glGetUniformLocation(p, "texB");
  glUniform1i(q, 1);
  int tc = glGetAttribLocation(p, "userTC"); //задание атрибута для передачи текстур

  glScalef(1, 1, 0.6);

  glBegin(GL_QUADS);
    //передняя грань
    glVertexAttrib2f(tc, 1, 0); //задание координат для атрибута userTC
    glVertex3f(0.5, 0.5, 1); //координаты вершины куба
    glVertexAttrib2f(tc, 1, 1);
    glVertex3f(0.5, -0.5, 1);
    glVertexAttrib2f(tc, 0, 1);
    glVertex3f(-0.5, -0.5, 1);
    glVertexAttrib2f(tc, 0, 0);
    glVertex3f(-0.5, 0.5, 1);
    //задняя грань
    glVertexAttrib2f(tc, 1, 0);
    glVertex3f(0.5, 0.5, -1);
    glVertexAttrib2f(tc, 1, 1);
    glVertex3f(0.5, -0.5, -1);
    glVertexAttrib2f(tc, 0, 1);
    glVertex3f(-0.5, -0.5, -1);
    glVertexAttrib2f(tc, 0, 0);
    glVertex3f(-0.5, 0.5, -1);
    //верхняя грань
    glVertexAttrib2f(tc, 1, 0);
    glVertex3f(0.5, 0.5, 1);
    glVertexAttrib2f(tc, 1, 1);
    glVertex3f(0.5, 0.5, -1);
    glVertexAttrib2f(tc, 0, 1);
    glVertex3f(-0.5, 0.5, -1);
    glVertexAttrib2f(tc, 0, 0);
    glVertex3f(-0.5, 0.5, 1);
    //нижняя грань
    glVertexAttrib2f(tc, 1, 0);
    glVertex3f(0.5, -0.5, 1);
    glVertexAttrib2f(tc, 1, 1);
    glVertex3f(0.5, -0.5, -1);
    glVertexAttrib2f(tc, 0, 1);
    glVertex3f(-0.5, -0.5, -1);
    glVertexAttrib2f(tc, 0, 0);
    glVertex3f(-0.5, -0.5, 1);
    //левая грань
    glVertexAttrib2f(tc, 1, 0);
    glVertex3f(-0.5, -0.5, 1);
    glVertexAttrib2f(tc, 1, 1);
    glVertex3f(-0.5, 0.5, 1);
    glVertexAttrib2f(tc, 0, 1);
    glVertex3f(-0.5, 0.5, -1);
    glVertexAttrib2f(tc, 0, 0);
    glVertex3f(-0.5, -0.5, -1);
    //правая грань
    glVertexAttrib2f(tc, 1, 0);
    glVertex3f(0.5, -0.5, 1);
    glVertexAttrib2f(tc, 1, 1);
    glVertex3f(0.5, 0.5, 1);
    glVertexAttrib2f(tc, 0, 1);
    glVertex3f(0.5, 0.5, -1);
    glVertexAttrib2f(tc, 0, 0);
    glVertex3f(0.5, -0.5, -1);
  glEnd();
}

void handleResize(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

//функция поворота
void timf() {
  // приращение угла поворота
  t = (float)glutGet(GLUT_ELAPSED_TIME)/30;
  // вызов функции перерисовки
  glutPostRedisplay();
}

void drawScene()
{
    glClearColor(0.35f, 0.53f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -12.0f);
    glRotatef(t, 0, 1, 1);
    glScaled(3, 3, 3); // увеличение в 3 раза;
    draw();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
  t = 0;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(500,200);
  glutInitWindowSize(500,400);
  glutCreateWindow("TEXTURE");
  texture_upload(); //загрузка текстур
  glutDisplayFunc(drawScene);
  glutIdleFunc(drawScene);
  glutReshapeFunc(handleResize);
  glClearColor(1.0,1.0,1.0,1.0);
  glewInit();
  setShaders();
  glutIdleFunc(timf);
  glutMainLoop();
  return 0;
}
