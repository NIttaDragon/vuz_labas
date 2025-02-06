/* ���� LrArrayDemo2_1.java
   ������������ ������ � 2-1 "������ �� �������� � ���������"
   
   �������:
   -------
   ���������� � ������� �����-����������, ������������ ������ main(), ���������� �����, ���������� 
   �������-����� �� �0��� �9�.
   ������� ������ ���� String ���������������� ������� ��� �������� �����, ������������ �� ����, 
   ��������� � �������-����������.
   ��������, ���� ������-�������� ����� ���: �nhgja5vbnjab67nja8vnn�, �� ������, ������������ �� 
   ��������-����, ����� ��������� ���: �5678�
   ������� � ���� ��������� �������� ������� �����-���������� � ������� �����, ���������� ������ 
   �������-�����.
   ������ �����-���������� ����� ���� ������, �. �. ��� ������� ��������� ����� �� ������������ 
   ������-���������. ������-��������� ����� �� �������� �������-�����. � ����� ������ ��������� ������ 
   �������� ���������.

   ��������: ������� ������ ���-111 ��������� �.�.
*/

import java.awt.*;
import java.awt.event.*;
public class LrArrayDemo2_1 extends Canvas
{
  // ���������� ����� ���� ��������
  String[] param;
  String[] DigitArray;
  
 // ����������� ������
 public LrArrayDemo2_1(String[] param)
 { 
  // ������������� ���� ������� �� ������ �����-����������
  // (��������, ������), ������������ ������ main(), 
  this.param = param;
  char s;
  int num = 0; 
  int count = 0;	// ����������-�������
  for (String str : param){
     int leng = str.length();
     for (int k=0; k<leng; k++){
       s = str.charAt(k);
       if(s >= '0' && s<='9')
          break;
     }; 
     count++;
   };
   DigitArray = new String[count]; // �������� ������� ����� (��������, �������)
   count = 0;
   num = 0;
   for (String str : param){
     String stri = " ";
     int leng = str.length();
     num = 0;
	 for(int k=0;k<leng;k++){
       s = str.charAt(k);
	   if(s>='0' && s<='9'){
		   stri=stri+s;
		   num++;
	   }
     };
     if(num==0) stri = " ���� � ������ ���";
     DigitArray[count] = stri;
     count++;
   };
 }

 public void paint(Graphics g)
 { 
  int i, y = 20;

  g.drawString("��������: ������� ������ ���-111 ��������� �.�.", 10, y);

  g.drawString("������ �����-���������� �������� ��������� ��������:", 10, y += 30);
  for(i = 0; i < param.length; i++)
       g.drawString("param[" + i + "] = " + param[i], 10, y += 20);
  
  g.drawString("������ ����� �������� ��������� ��������:", 10, y += 30);
  for(i = 0; i < DigitArray .length; i++)
       g.drawString("DigitArray [" + i + "] = " + DigitArray [i], 10, y += 20);
 }

 public static void main(String args[])   // ����� ���� � ���������
 {
  LrArrayDemo2_1 canvas = new LrArrayDemo2_1 (args);
  canvas.setFont (new Font("Arail", Font.PLAIN, 18));
  Frame frame = new Frame("������������ ������ � 2_1");	
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
