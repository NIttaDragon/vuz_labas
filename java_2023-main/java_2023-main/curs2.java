import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import java.util.*;

public class AnimBallsPlus extends JPanel implements AdjustmentListener, ActionListener, ItemListener
{
  Thread anim1, anim2; //
  Rec thred1; //
  Adv thred2;
 Canvas p_left;
 JPanel p_center, p_right;
 Panel  p1, p2, p3, p4, p5, p_0, p_1, p_2;
 TextField tf;
 Button b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11;
 Checkbox cb1, cb2;
 CheckboxGroup cbg;
 Scrollbar sb;
 ActionListener al;
 Font ft = new Font("Dialog", Font.BOLD, 35);
 String acm, acm1, str, val = "text";
 int sb_val = 30, str_x = 1, height = 300, weight = 200;
 boolean flag = true;
 Choice ch;
 Label lb1, lb2, lb3, lb4, lb5;
 int che = 0; //
 boolean stop_flag = true; //

 public AnimBallsPlus()
    {
		setLayout(new GridLayout(1, 1));
		p_left = new Canvas(){
      Image buffer; //
      Graphics gc; //
      public void update(Graphics g) {//
            paint(g);//
      }//
			public void paint(Graphics g){
        buffer = createImage(getSize().width, getSize().height); //
        gc = buffer.getGraphics(); //
				Dimension size = p_left.getSize();
				gc.setColor(Color.red);
				gc.drawRect(0, 0, weight, height);
				if("pink".equals(acm)) gc.setColor(Color.pink);
				else if("blue".equals(acm)) gc.setColor(Color.blue);
				else if("gray".equals(acm)) gc.setColor(Color.gray);
				else if("green".equals(acm)) gc.setColor(Color.green);
				else if("magenta".equals(acm)) gc.setColor(Color.magenta);
				else if("cyan".equals(acm)) gc.setColor(Color.cyan);
				else if("orange".equals(acm)) gc.setColor(Color.orange);
				else if("red".equals(acm)) gc.setColor(Color.red);
				else if("yellow".equals(acm)) gc.setColor(Color.yellow);
				str = tf.getText();
				gc.setFont(ft);//
				double v = sb_val*0.01*size.height;
				if (!flag) gc.drawString(str, str_x, (int)v);
        g.drawImage(buffer, 0, 0, this); //
			}
		};
		p_left.setBackground(Color.white);
		p_left.setForeground(Color.black);
		add(p_left);

		p_center = new JPanel();
		p_center.setLayout(new GridLayout(3, 1)); //
		p_center.setBackground(new Color(255, 255, 155));
		p_center.setBorder(BorderFactory.createLineBorder(Color.black,1));

		p1 = new Panel();
		p1.setLayout(new GridLayout(3, 3, 2, 2));
		b1 = new Button("pink");
		b1.addActionListener(this);
		p1.add(b1);
		b2 = new Button("blue");
		b2.addActionListener(this);
		p1.add(b2);
		b3 = new Button("gray");
		b3.addActionListener(this);
		p1.add(b3);
		b4 = new Button("green");
		b4.addActionListener(this);
		p1.add(b4);
		b5 = new Button("magenta");
		b5.addActionListener(this);
		p1.add(b5);
		b6 = new Button("cyan");
		b6.addActionListener(this);
		p1.add(b6);
		b7 = new Button("orange");
		b7.addActionListener(this);
		p1.add(b7);
		b8 = new Button("red");
		b8.addActionListener(this);
		p1.add(b8);
		b9 = new Button("yellow");
		b9.addActionListener(this);
		p1.add(b9);
		p_center.add(p1);

		p2 = new Panel();
		lb1 = new Label("Chose draw option:",Label.CENTER);
		lb1.setForeground(Color.black);
		p2.add(lb1);

		cbg = new CheckboxGroup();
		cb1 = new Checkbox("clear", cbg, true);
		cb2 = new Checkbox("draw", cbg, false);
		cb1.addItemListener(this);
		cb2.addItemListener(this);
		p2.add(cb1);
		p2.add(cb2);
		p_center.add(p2);

    //
    p_2 = new Panel();
    lb5 = new Label("Chose thread option:",Label.CENTER);
		lb5.setForeground(Color.black);
		p_2.add(lb5);
    b10 = new Button("Start");
    b10.addActionListener(new ActionListener(){ //регистрация приёмника
      public void actionPerformed(ActionEvent e){ //реализация приёмника
        startThread();
      }
    });
    b11 = new Button("Stop");
    b11.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent e){
        stopThread();
      }
    });
    if(flag){
      b10.setEnabled(false);
      b11.setEnabled(false);
    }
    p_2.add(b10);
    p_2.add(b11);
	  p_center.add(p_2);
	  add(p_center);

		p_right = new JPanel();
		p_right.setLayout(new GridLayout(3, 1));
		p_right.setBackground(new Color(255, 255, 155));
		p_right.setBorder(BorderFactory.createLineBorder(Color.black,1));

		p3 = new Panel();
		lb2 = new Label("Chose font:",Label.CENTER);
		lb2.setForeground(Color.black);
		p3.add(lb2);

		ch = new Choice();
		ch.addItem("Dialog");
		ch.addItem("SansSerif");
		ch.addItem("Monospaced");
		ch.addItem("Serif");
		ch.addItem("DialogInput");
		ch.addItemListener(new ItemListener()
		{
			public void itemStateChanged(ItemEvent e) {
				acm1 = (String)e.getItem();
				if("Dialog".equals(acm1))
					ft = new Font("Dialog", Font.BOLD, 35);
				else if("SansSerif".equals(acm1))
					ft = new Font("SansSerif", Font.BOLD, 35);
				else if("Monospaced".equals(acm1))
					ft = new Font("Monospaced", Font.BOLD, 35);
				else if("Serif".equals(acm1))
					ft = new Font("Serif", Font.BOLD, 35);
				else if("DialogInput".equals(acm1))
					ft = new Font("DialogInput", Font.BOLD, 35);
			}});
		p3.add(ch);
		p_right.add(p3, BorderLayout.NORTH);

		p4 = new Panel();
		p4.setLayout(new BorderLayout());

		p_1 = new Panel();
		p_1.setLayout(new BorderLayout());
		lb3 = new Label("enter text:",Label.CENTER);
		lb3.setForeground(Color.black);
		p_1.add(lb3, BorderLayout.SOUTH);
		p4.add(p_1, BorderLayout.CENTER);

		tf = new TextField(val, 1);
		tf.addActionListener(al = new ActionListener(){
			public void actionPerformed(ActionEvent e){
				p_left.repaint();
				tf.addTextListener(new TextListener(){
					public void textValueChanged(TextEvent e){
						p_left.repaint();
					}
				});
				tf.removeActionListener(al);
			}
		});
		p4.add(tf, BorderLayout.SOUTH);
		p_right.add(p4);

		p5 = new Panel();
		p5.setLayout(new BorderLayout());
		p_0 = new Panel();
		p_0.setLayout(new BorderLayout());
		lb4 = new Label("up or down:", Label.CENTER);
		lb4.setForeground(Color.black);
		p_0.add(lb4, BorderLayout.SOUTH);
		p5.add(p_0, BorderLayout.CENTER);

		sb = new Scrollbar(Scrollbar.HORIZONTAL, 10, 0, 5, 100);
		sb.addAdjustmentListener(this);
		p5.add(sb, BorderLayout.SOUTH);
		p_right.add(p5, BorderLayout.SOUTH);
		add(p_right);
  }

  public void itemStateChanged(ItemEvent ie){
    flag = !flag;
		if(!flag) {
			ch.setEnabled(false);
			tf.setEnabled(false);
			sb.setEnabled(true);
      b10.setEnabled(true);//
      b11.setEnabled(true);//
		}
		else {
			ch.setEnabled(true);
			tf.setEnabled(true);
			sb.setEnabled(false);
      b10.setEnabled(false);//
      b11.setEnabled(false);//
      stopThread();//
		}
		p_left.repaint();
  }

  public void adjustmentValueChanged(AdjustmentEvent e){
		sb_val = e.getValue();
		p_left.repaint();
  }

  public void actionPerformed(ActionEvent e)
  {
		acm = e.getActionCommand();
		if("pink".equals(acm)) b1.setBackground(Color.pink);
		else if("blue".equals(acm)) b2.setBackground(Color.blue);
		else if("gray".equals(acm)) b3.setBackground(Color.gray);
		else if("green".equals(acm)) b4.setBackground(Color.green);
		else if("magenta".equals(acm)) b5.setBackground(Color.magenta);
		else if("cyan".equals(acm)) b6.setBackground(Color.cyan);
		else if("orange".equals(acm)) b7.setBackground(Color.orange);
		else if("red".equals(acm)) b8.setBackground(Color.red);
		else if("yellow".equals(acm)) b9.setBackground(Color.yellow);
		p_left.repaint();
  }

//
  synchronized void rec_trans(){ //
    while(!stop_flag) //
      try{wait();} //
      catch(InterruptedException e){}
    weight--;
    height--;
    che++;
    if(che == 50){
      che = 0;
      stop_flag = false; //
    }
    if(weight<=0)  weight = 200;
    if(height<=0)  height = 300;
    notifyAll(); //
  }

    synchronized void text_move(){
      while(stop_flag)
      try{wait();}
        catch(InterruptedException e){}
      str_x--;
      if(str_x <= 0) {
        str_x = 200;
        stop_flag = true;
      }
      notifyAll();

  }

	//����� ��� ������ �������� ��������������
	class Rec implements Runnable{
    AnimBallsPlus panel; //
    Rec(AnimBallsPlus panel){//
      this.panel = panel; //
      new Thread(this, "Rec").start(); //
    }
		public void run(){ //
      Thread thisThread = Thread.currentThread(); //
      while(panel.anim1 == thisThread){ //
        panel.rec_trans(); //
        panel.p_left.repaint();
        try{ //
          Thread.currentThread().sleep(30); //
        } catch (InterruptedException e){
          return;
        }
      }
  	}
	}

	//����� ������ �������� ������
	class Adv implements Runnable{
    AnimBallsPlus panel;
    Adv(AnimBallsPlus panel){
      this.panel = panel;
      new Thread(this, "Adv").start();
    }
		public void run(){
      Thread thisThread = Thread.currentThread();
      while(panel.anim2 == thisThread){
        panel.text_move();
        panel.p_left.repaint();
        try{
          Thread.currentThread().sleep(20);
        } catch (InterruptedException e){
          return;
        }
      }
  	}
	}

     //����� ������������� � ������� �������
  private void startThread(){
    anim1 = new Thread(new Rec(this));
    anim2 = new Thread(new Adv(this));
    anim1.start();
    anim2.start();
	 }

	//����� ��������� �������
	public void stopThread(){
		anim1 = null;
    anim2 = null;
	}

	public static void main(String args[]) {
		final AnimBallsPlus panel = new AnimBallsPlus();
		Frame frame = new Frame("Uspenskaya T.A IVB-111 Curs (with animation)");
		frame.add(panel);
		frame.setSize(800, 400);
		frame.setLocation(100, 100);
		frame.setVisible(true);
		frame.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}
}
