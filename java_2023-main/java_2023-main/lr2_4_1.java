/* ��������� ��������� �.� ���-111
   �������.

	1) ������� ������ ���� String, ������� ����� �� 1 �������, ��� ������ ����������, 
	� ����������� � ���� ������-���������, ������� ��������� ������� ��������������������.
    ���������� ������� ������� � ����� ������� ������� �, �������� ������ �� ��� ������ 
	(���� ���������� �������� �������� - ��� �������� ������) �����, ������� ��� ������� 
	�������� ��������������� �������. 
	��� ������� ������ �������� � �������������� ������ �������� ����� ������� � 
	����������-������� � ����������, �������������� ����� ������� ������������ ��������. 
	��������� ������: insert(String elem, int index)
*/

import java.awt.*;
import java.awt.event.*;
public class ArrayDemo2 extends Canvas
{
  // ���������� ����� ���� ��������
  String[] param;
  String[] paramClone;
 
 // ����������� ������
 public ArrayDemo2(String[] param)
 { 
  // ������������� ���� ������� �� ������ �����-���������� (��������, ������), 
	 //������������ ������ main(), 
  this.param = param;
 		
  paramClone = new String[param.length+1]; // ������-���� ���������� ������� �����
  for(int i=0; i<paramClone.length-1; i++)
	paramClone[i] = param[i];
  
  int max = 0;
  int max_id = 0;
  String str_1, str_2;
  
  //���������� ����� ������� ������ � ������
  for(int i=0; i<paramClone.length-1;i++){
	if(paramClone[i].length()>max){
		max_id = i;
		max = paramClone[i].length();
	}
  }
  
  int len = paramClone[max_id].length() / 2;
  str_1 = paramClone[max_id].substring(0, len);
  str_2 = paramClone[max_id].substring(len, paramClone[max_id].length());
  paramClone[max_id] = str_1;
  insert(str_2, max_id+1);
 }
 public void insert(String elem, int index){
	for(int i=paramClone.length-1; i>index-1;i--)
		paramClone[i]=paramClone[i-1];
	paramClone[index]=elem;
 }

 public void paint(Graphics g)
 { 
  int i, y = 30;
  g.drawString("������ �����-���������� �������� ��������� ��������:", 10, y);
  for(i = 0; i < param.length; i++)
       g.drawString("param[" + i + "] = " + param[i], 10, y += 25);
  
  g.drawString("������ ����� �������� ��������� ��������:", 10, y += 50);
  for(i = 0; i < paramClone.length; i++)
       g.drawString("totalRow[" + i + "] = " + paramClone[i], 10, y += 25);
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
