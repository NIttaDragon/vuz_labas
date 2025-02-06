/* ���� ArrayDemo2.java
   ������ ������ � ��������� � ��������
   ------------------------------------
   �������.

	������� ������, ����������� ������ �����-����������.
	���������� ����� ������� ������ ������� � ����������� �� � ������ �������. (��� 
	���� �������� �������, ������� ������� �������, ��� ������ ��������� ������, 
	���������� �� ���� ������� ������.)
	�������� � �������� ������ ������ ��������� ������������� �� ������� � �������.
	������� � ���� ��������� �������� ������� �����-���������� � ��������������� �������.
	������ �����-���������� ����� ���� ������, �. �. ��� ������� ��������� ����� �� 
	������������ ������-���������. � ����� ������ ��������� ������ �������� ���������.
*/


import java.awt.*;
import java.awt.event.*;
public class ArrayDemo2 extends Canvas
{
  // ���������� ����� ���� ��������
  String[] param;
  String[] paramClone;
  String[] totalRow;
 
 // ����������� ������
 public ArrayDemo2(String[] param)
 { 
  // ������������� ���� ������� �� ������ �����-����������
  // (��������, ������), ������������ ������ main(), 
  this.param = param;
 		
  int count = 0;	// ����������-�������
  paramClone = new String[param.length]; // ������-���� ���������� ������� �����
  totalRow = new String[param.length+1]; // �������� ������
  for (String str : param){
     paramClone[count] = str;
     count++;
  };
  
  boolean sorted = false;
  int max = 0;
  int max_id = 0;
  String stri;
  
  //������� ����� ������� ������ � ������
  for(int i=0; i<paramClone.length-1;i++){
	if(paramClone[i].length()>max){
		max_id = i;
		max = paramClone[i].length();
	}
  }
  stri = paramClone[max_id];
  for(int i=max_id; i>0; i--){
	paramClone[i]=paramClone[i-1];
  }
  paramClone[0]=stri;
  
  //������ � �������� ������ �� �������
  for(int i=0; i<paramClone.length; i++){
	int len = paramClone[i].length() / 2;
	String str_1, str_2;
	str_1 = paramClone[i].substring(0, len);
	str_2 = paramClone[i].substring(len, paramClone[i].length());
	totalRow[i] = str_1+String.format("%d",i)+str_2;
  }
 }

 public void paint(Graphics g)
 { 
  int i, y = 30;
  g.drawString("������ �����-���������� �������� ��������� ��������:", 10, y);
  for(i = 0; i < param.length; i++)
       g.drawString("param[" + i + "] = " + param[i], 10, y += 25);
  
  g.drawString("������ ����� �������� ��������� ��������:", 10, y += 50);
  for(i = 0; i < paramClone.length; i++)
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
