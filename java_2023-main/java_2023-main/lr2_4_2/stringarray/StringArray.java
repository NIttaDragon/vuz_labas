package stringarray;

public class StringArray { 
  String[] param;
  // Объявление полей типа массивов
  public String[] paramClone;
 
 public StringArray(String[] param)
 { 
  this.param = param;
  paramClone = new String[param.length+1]; // массив-клон начального массива строк
  for(int i=0; i<paramClone.length-1; i++)
	paramClone[i] = param[i];
 }
 
 public int searchMaxRow (){
  int max = 0;
  int max_id = 0;
  String str_1, str_2;
  
  for(int i=0; i<paramClone.length-1;i++){
	if(paramClone[i].length()>max){
		max_id = i;
		max = paramClone[i].length();
	}
  }
  return max_id;
 }
}