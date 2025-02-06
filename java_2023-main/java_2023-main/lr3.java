/* ���� ArrayDemo2.java
   ������ ������ � ��������� � ��������
   ------------------------------------
   �������.

	���������� � ������� �����-����������, ������������ ������ main(), ���������� �����, 
	���������� ���������� ��������������� ����� ����� ������� int, � ������� ������ 
	������ Integer
	static int parseInt(String s) throws NumberFormatException
	� ��������� ���������� ���� NumberFormatException.
	������� ������ ���� int ���������������� ������� � �������� � ������ �����, ���������� 
	� ���������� �������������� ��������� ������������� � int-�����. 
	���������� ���������� � ���������� �������� ������� ���� int, � ����� ����� ��������� �������.  
	������� � ���� ��������� �������� ������� �����-���������� � ��������������� ������� ���� int, 
	� ����� ���������� � ���������� �������� �������, ����� ��������� �������.
	������ �����-���������� ����� ���� ������, �. �. ��� ������� ��������� ����� �� ������������ 
	������-���������. � ����� ������ ��������� ������ �������� ���������.
*/

import java.awt.*;
import java.awt.event.*;
public class ArrayDemo2 extends Canvas
{
  // ���������� ����� ���� ��������
  String[] param;
  int[] IntArray;
  int sum;
  int max;
  int min;
  int count;
 
 // ����������� ������
 public ArrayDemo2(String[] param)
 { 
  // ������������� ���� ������� �� ������ �����-���������� (��������, ������), ������������ ������ main(), 
  this.param = param;
 		
  count = 0;
  IntArray = new int[param.length];
  for(String str : param){
	if(parsesInt(str) !=0){
		IntArray[count] = parsesInt(str);
		count++;
	}
  }
  
  sum = 0;
  min = 10000;
  max = 0;
  for(int i = 0; i<count; i++){
	sum +=IntArray[i];
	if(IntArray[i]<min)
		min = IntArray[i];
	if(IntArray[i]>max)
		max = IntArray[i];
  }
 }
 
 public static int parsesInt (String s) throws NumberFormatException{
	int num=0;
	try{
		num = Integer.parseInt(s);
	} catch (NumberFormatException e){
		System.out.println ("�������� - "+e.toString());
	}
	return num;
 }

 public void paint(Graphics g)
 { 
  int i, y = 30;
  g.drawString("������ �����-���������� �������� ��������� ��������:", 10, y);
  for(i = 0; i < param.length; i++)
       g.drawString("param[" + i + "] = " + param[i], 10, y += 25);
  
  g.drawString("������ ����� �������� ��������� ��������:", 10, y += 50);
  for(i = 0; i < count; i++)
       g.drawString("IntArray[" + i + "] = " + IntArray[i], 10, y += 25);
   
  g.drawString("�����:", 10, y += 50);
  g.drawString("sum = " + sum, 10, y += 25);
  g.drawString("���������� �������:", 10, y += 50);
  g.drawString("max = " + max, 10, y += 25);
  g.drawString("���������� �������:", 10, y += 50);
  g.drawString("min = " + min, 10, y += 25);
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
