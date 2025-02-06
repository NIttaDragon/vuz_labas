/* ���� ArrayDemo2.java
   ������ ������ � ��������� � ��������
   ------------------------------------
   �������.

   ������� ������, ����������� ������ �����-����������.
   ������������� ����� ������ �� ����� ������, ��������� �����
 ��������� �������� ����������.
   �������������: �������� � ������ ������ ������ ��������� 
������������� ����� ���� ������ � ������ �� ��������� ����� 
�������.
   ������� � ���� ��������� �������� ������� �����-���������� 
� ��������������� �������.
   ������ �����-���������� ����� ���� ������, �. �. ��� ������� 
��������� ����� �� ������������ ������-���������. � ����� 
������ ��������� ������ �������� ���������.

*/

import java.awt.*;
import java.awt.event.*;
public class ArrayDemo2 extends Canvas
{
  // ���������� ����� ���� ��������
  String[] param;
  String[] paramClone;
  int[] paramLength;
  String[] totalRow;

 // ����������� ������
 public ArrayDemo2(String[] param)
 { 
  // ������������� ���� ������� �� ������ �����-����������
  // (��������, ������), ������������ ������ main(), 
  this.param = param;
 		
  int count = 0;	// ����������-�������
  paramLength = new int[param.length];
  paramClone = new String[param.length];
  totalRow = new String[param.length];
  for (String str : param){
     paramClone[count] = str;
     paramLength[count] = str.length();
     count++;
  };
  
  boolean sorted = false;
  int temp;
  String tmep;
  while(!sorted){
    sorted = true;
    for(int i=0; i<paramClone.length-1; i++){
      if(paramLength[i]>paramLength[i+1]){
         temp = paramLength[i];
         paramLength[i]=paramLength[i+1];
         paramLength[i+1]=temp;
         tmep = paramClone[i];
         paramClone[i]=paramClone[i+1];
         paramClone[i+1]=tmep;
         sorted = false;
      };
    };
  };
  
  String str;
  int len;
  for(int i=0; i<paramClone.length;i++){
    str = String.format("%d", paramLength[i]);
    len = str.length()+paramLength[i];
    for (int k = 1; k < 10; k++) {
	if (((Math.pow(10, k) - k) <= paramLength[i])&&(paramLength[i]<Math.pow(10,k))){
		len+=1;
		break;
        }
    }
    totalRow[i] = String.format("%d",len)+paramClone[i];
  };
 }

 public void paint(Graphics g)
 { 
  int i, y = 30;
  g.drawString("������ �����-���������� �������� ��������� ��������:", 10, y);
  for(i = 0; i < param.length; i++)
       g.drawString("param[" + i + "] = " + param[i], 10, y += 25);
  
  g.drawString("������ ����� �������� ��������� ��������:", 10, y += 50);
  for(i = 0; i < paramLength.length; i++)
       g.drawString("totalRow[" + i + "] = " + totalRow[i], 10, y += 25);
 }

 public static void main(String args[])   // ����� ���� � ���������
 {
  ArrayDemo2 canvas = new ArrayDemo2 (args);
  canvas.setFont (new Font("TimesRoman", Font.PLAIN, 18));
  Frame frame = new Frame("ArrayDemo2 Application");	
  frame.add(canvas);
  frame.setSize(550, 500);
  frame.setLocation(100, 100);
  frame.setVisible(true);
  frame.addWindowListener(new WindowAdapter(){
        public void windowClosing(WindowEvent e){
               System.exit(0);
       }
  });
 } 
}
