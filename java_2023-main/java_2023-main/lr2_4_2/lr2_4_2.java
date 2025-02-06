/* ��������� ��������� �.� ���-111
   �������.

	2) ����������� ����� StringArray, � ������� ������� ���� ��� �������� ������� ����� � 
	������ ��� ������ � ��������. ����� ����������� � ��������� ������ stringarray. 
	������� ������ ���� StringArray � ����������� � ���� ������ ������� ����������.
	���������� ������� ������� � ����� ������� ������� �, �������� ������ �� ��� ������ 
	(���� ���������� �������� �������� ? ��� �������� ������) �����, ������� ��� ������� 
	�������� ��������������� �������. 
	��� ������ � �������� ������������ ������ ������ StringArray.
*/

import java.awt.*;
import java.awt.event.*;
import stringarray.StringArray;

public class ArrayDemo2_1 extends Canvas
{
  // ���������� ����� ���� ��������
  String[] param;
  StringArray stra;
 
 // ����������� ������
 public ArrayDemo2_1(String[] param)
 { 
     this.param = param;
	int max_id;
	stra = new StringArray(this.param);
	//stra.CloneArray(param);
	
    String str_1, str_2;
	
	max_id = stra.searchMaxRow();
  
	int len = stra.paramClone[max_id].length() / 2;
	str_1 = stra.paramClone[max_id].substring(0, len);
	str_2 = stra.paramClone[max_id].substring(len, stra.paramClone[max_id].length());
	stra.paramClone[max_id] = str_1;
	
	for(int i=stra.paramClone.length-1; i>max_id;i--)
		stra.paramClone[i]=stra.paramClone[i-1];
	stra.paramClone[max_id+1]=str_2;
 }

 public void paint(Graphics g)
 { 
  int i, y = 30;
  g.drawString("������ �����-���������� �������� ��������� ��������:", 10, y);
  for(i = 0; i < param.length; i++)
       g.drawString("param[" + i + "] = " + param[i], 10, y += 25);
  
  g.drawString("������ ����� �������� ��������� ��������:", 10, y += 50);
  for(i = 0; i < stra.paramClone.length; i++)
       g.drawString("totalRow[" + i + "] = " + stra.paramClone[i], 10, y += 25);
 }

 public static void main(String args[])   // ����� ���� � ���������
 {
  ArrayDemo2_1 canvas = new ArrayDemo2_1 (args);
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
