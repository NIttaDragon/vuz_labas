#version 110 //фрагментный шейдер

uniform sampler2D texA; //передача текстуры из основной программы
uniform sampler2D texB;
varying vec2 texCoord; //соединение переменных между шейдерами
void main(){
  //запись результатов фрагментного шейдера
  gl_FragColor = (texture2D(texA, texCoord) + texture2D(texB, texCoord))*0.5; //смешение цветов изображений - мультитекстурирование
}
