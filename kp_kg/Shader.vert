#version 110 //вершинный шейдер

attribute vec2 userTC; //атриут для передачи собственных координат
varying vec2 texCoord; //соединение переменных между шейдерами
void main()
{
  gl_Position = gl_Vertex; //запись результатов вершинного шейдера
  texCoord = userTC; //передача координат для расположения текстуры
  gl_Position = ftransform(); //
}
