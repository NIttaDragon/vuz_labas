#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

// M/E2/1

//генерация экспоненциального распределения
float Mark(float lambda_expo) {
  float x = rand();
  float Mark_time = -1/lambda_expo*log(x);
  return Mark_time;
}

//генерация эрланговского распределения
float Erlang(float mu1, float mu2) {
  float Erlang_time_1 = Mark(2*mu1);
  float Erlang_time_2 = Mark(2*mu2);
  float Erlang_time = Erlang_time_1 + Erlang_time_2;
  return Erlang_time;
}

int main() {
  float start_moment, //стартовый момент
  lambda_expo, //лямбда для экспоненциального распределения
  mu1, mu2, //лямюда для эрланговского распределения
  modeling_limit, //пределы моделирования
  Mark_time, //время между прибытием очередной и предыдущей заявок
  Erlang_time, //длительность обслуживания очередной заявки
  Summ_alf, //сумма альф
  Summ_bet, //сумма бет
  Model_time, //модельное время
  T_z, // момент прибытия очередной заявки
  T_osv, // момент освобождения занятого канала обслуженной заявки
  Ro, //загрузка
  Summ_time, //суммарное время пребывания в системе
  Sred_time; //среднее время пребывания в системе
  int //users = 1000, //5000
  n, //текущее число заявок в системе
  //n_otk, //число отказов
  n_obs; //число обслуженных заявок
  //float tt[1000]; //?
  bool contin = true; //цикл работы основной программы
  int exit; //реение пользователя о работе программы

  while(contin){
    //входные данные
    cout<<"Enter start moments"<<endl;
    cin>>start_moment;
    cout<<"Enter lambda_expo"<<endl; //0.1? 0.5? 0.9
    cin>>lambda_expo; //Как параметр и как интенсивность
    cout<<"Enter mu1 and mu2"<<endl;
    cin>>mu1;
    cin>>mu2;
    cout<<"Enter modeling limit"<<endl;
    cin>>modeling_limit;

    float bet1 = 1/(2*mu1)+1/(2*mu2);
    cout<<"bet1: "<<bet1<<endl;
    Ro = lambda_expo*bet1;
    cout<<"Ro: "<<Ro<<endl;

    //очистка счётчиков
    /*n_otk = 0;*/ Sred_time = 0; Summ_time = 0; n = 0; n_obs = 0; Summ_alf = 0; Summ_bet = 0; Model_time = 0; T_osv = 99999;
    bool per1 = true, per2 = true;
    while(per1){
      //формирование времени поступления заявки
      Mark_time = Mark(lambda_expo);
      Summ_alf += Mark_time;
      T_z = Model_time + Mark_time;
      if(T_z>T_osv){
        per1 = false;
        break;
      }
      else{
        Model_time=T_z;
        n++;
        if(n == 1){
          Erlang_time = Erlang(mu1, mu2);
          T_osv = Model_time + Erlang_time;
        }
      }
      /*if(n>users){
        n=users;
        n_otk++;
      }
      else tt[n] = Model_time;*/
    }
    while(per2){
      Model_time = T_osv;
      n--;
      if(n==0) T_osv = 99999;
      else{
        Erlang_time = Erlang(mu1, mu2);
        T_osv = Model_time + Erlang_time;
      }
      Summ_time+=(Model_time/*-tt[1]*/);
      /*for(int i=1; i<n; i++){
        tt[i]=tt[i+1];
      }*/
      n_obs++;
      if(Model_time>=modeling_limit){
        per2 = false;
        break;
      }
    }
    Sred_time = Summ_time/n_obs;
    cout<<"Sred_time: "<<Sred_time<<endl;

    //продолжить ли вычисления
    cout<<"Do you want to exit?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;
    cin>>exit;
    if(exit==2) contin = true;
    else contin = false;
  }

  //выходные данные
  float Wsr, Tsr, tvsr, kvar;

  return 0;
}
