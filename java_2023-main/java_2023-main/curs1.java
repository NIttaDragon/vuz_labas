import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import java.util.*;

public class AnimBallsPlus extends JPanel implements AdjustmentListener, ActionListener, ItemListener{
Canvas p_left; //правая панель канвы
JPanel p_center, p_right; //панели с обводкой
Panel  p1, p2, p3, p4, p5, p_0, p_1; //обычные панели
TextField tf; //текстовое поле
Button b1, b2, b3, b4, b5, b6, b7, b8, b9; //кнопки
Checkbox cb1, cb2; //радиокнопки
CheckboxGroup cbg; //группа для радиокнопок
Scrollbar sb; //скролбар
ActionListener al; //объект для обработки событий текстового поля
Font ft = new Font("Dialog", Font.BOLD, 35); //задание начального шрифта
String acm, acm1, str, val = "text";
int sb_val = 30, height, width,sb_height;
boolean flag = true;
Choice ch; //список
Label lb1, lb2, lb3, lb4; //лейблы

public AnimBallsPlus(){
//холст слева
	setLayout(new GridLayout(1, 1)); //задаётся сетка разметки
	p_left = new Canvas(){
		public void paint(Graphics g){	
			Dimension size = p_left.getSize(); //получение размера канвы
			height = size.height-5;
			width = size.width-5;
			//создание прямоугольника на фоне
			g.setColor(Color.red);
			g.drawRect(0, 0, width, height);
			//изменение цвета текста по нажатию кнопки
			if("розовый".equals(acm)) g.setColor(Color.pink);
			else if("синий".equals(acm)) g.setColor(Color.blue);
			else if("серый".equals(acm)) g.setColor(Color.gray);
			else if("зелёный".equals(acm)) g.setColor(Color.green);
			else if("фиолетовый".equals(acm)) g.setColor(Color.magenta);
			else if("голубой".equals(acm)) g.setColor(Color.cyan);
			else if("оранжевый".equals(acm)) g.setColor(Color.orange);
			else if("красный".equals(acm)) g.setColor(Color.red);
			else if("жёлтый".equals(acm)) g.setColor(Color.yellow);
			str = tf.getText(); //получение строки из панели
			g.setFont(ft); //установка шрифта для текста
			//задание координат текста
			double v = sb_val*0.01*size.height;
			if (!flag) g.drawString(str, 1, (int)v);
		}
	};
	p_left.setBackground(Color.white); //задание цвета фона
	add(p_left); //добавление канвы на фрейм

	//центральная панель
	p_center = new JPanel();
	p_center.setLayout(new GridLayout(2, 1));
	p_center.setBackground(new Color(255, 255, 155)); //задаётся фоновый цвет
	p_center.setBorder(BorderFactory.createLineBorder(Color.black,1)); //обводка

	//панель кнопок
	p1 = new Panel();
	p1.setLayout(new GridLayout(3, 3, 2, 2));
	b1 = new Button("розовый"); //создание кнопки
	b1.addActionListener(this); //регистрация приёмника
	p1.add(b1); //добавление кнопки на панель кнопок
	b2 = new Button("синий");
	b2.addActionListener(this);
	p1.add(b2);
	b3 = new Button("серый");
	b3.addActionListener(this);
	p1.add(b3);
	b4 = new Button("зелёный");
	b4.addActionListener(this);
	p1.add(b4);
	b5 = new Button("фиолетовый");
	b5.addActionListener(this);
	p1.add(b5);
	b6 = new Button("голубой");
	b6.addActionListener(this);
	p1.add(b6);
	b7 = new Button("оранжевый");
	b7.addActionListener(this);
	p1.add(b7);
	b8 = new Button("красный");
	b8.addActionListener(this);
	p1.add(b8);
	b9 = new Button("жёлтый");
	b9.addActionListener(this);
	p1.add(b9);
	p_center.add(p1); //добавление панели кнопок на центральную панель

	//панель радиокнопок
	p2 = new Panel();
	//лейбл для радиокнопок
	lb1 = new Label("Выбор режима рисования:",Label.CENTER);
	lb1.setForeground(Color.black); //задание цвета лейбла
	p2.add(lb1); //добавление лейбла на панель радиокнопок
	//радиокнопки
	cbg = new CheckboxGroup(); //создание группы чекбоксов
	//создание чекбоксов, установка начального значения
	cb1 = new Checkbox("Остановка", cbg, true);
	cb2 = new Checkbox("Рисование", cbg, false);
	//регистрация приёмников
	cb1.addItemListener(this);
	cb2.addItemListener(this);
	//добавление радиокнопок на панель
	p2.add(cb1);
	p2.add(cb2);
	p_center.add(p2); //добавление панели кнопок на центральную панель
add(p_center); //добавление центральной панели на фрейм

	//правая панель
	p_right = new JPanel();
	p_right.setLayout(new GridLayout(3, 1));
	p_right.setBackground(new Color(255, 255, 155));
p_right.setBorder(BorderFactory.createLineBorder(Color.black,1));
	  
	//панель шрифтов
	p3 = new Panel();
	//лейбл для выбора шрифтов
	lb2 = new Label("Выбор шрифта:",Label.CENTER);
	lb2.setForeground(Color.black);
	p3.add(lb2);

	//выбор шрифта
	ch = new Choice(); //выпадающий список
	//добавление элементов выпадающего списка
	ch.addItem("Dialog");
	ch.addItem("SansSerif");
	ch.addItem("Monospaced");
	ch.addItem("Serif");
	ch.addItem("DialogInput");
	//регистрация и реализация приёмника для выпадающего списка
	ch.addItemListener(new ItemListener(){
		public void itemStateChanged(ItemEvent e) {
			acm1 = (String)e.getItem(); //получение выбранного объекта
			//выбор значения из списка и применение к тексту
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
	p3.add(ch); //добавление выпадающего списка на панель
	p_right.add(p3, BorderLayout.NORTH); //добавление панели шрифтов на центральную панель

	//панель текста
	p4 = new Panel();
	p4.setLayout(new BorderLayout());
	p_1 = new Panel(); //вспомогательная панель для лейбла
	p_1.setLayout(new BorderLayout());
	//лейбл для текста
	lb3 = new Label("Введите текст:",Label.CENTER);
	lb3.setForeground(Color.black);
	p_1.add(lb3, BorderLayout.SOUTH); //добавление лейбла на панель
	p4.add(p_1, BorderLayout.CENTER); //добавление панели на панель текста

	//текстовое поле
	tf = new TextField(val, 1); //создание текстового поля с начальным текстом
	//регистрация и реализация приёмника для текстового поля
	tf.addActionListener(al = new ActionListener(){
		public void actionPerformed(ActionEvent e){
			p_left.repaint(); //перерисовка канвы
			//ввод текста
			tf.addTextListener(new TextListener(){
				public void textValueChanged(TextEvent e){
					p_left.repaint();
				}
			});
			tf.removeActionListener(al);
        		}
	});
	p4.add(tf, BorderLayout.SOUTH); //добавление текстового поля на панель
	p_right.add(p4); //добавление панели текста на правую панель

	//панель скрола
	p5 = new Panel();
	p5.setLayout(new BorderLayout());
	p_0 = new Panel(); //вспомогательная панель для лейбла
	p_0.setLayout(new BorderLayout());
	//лейбл для скрола
	lb4 = new Label("Движение текста вниз/вверх:", Label.CENTER);
	lb4.setForeground(Color.black);
	p_0.add(lb4, BorderLayout.SOUTH); //добавление лейбла на панель
	p5.add(p_0, BorderLayout.CENTER); //добавление панели на панель скрола
	
	//скролбар
	sb = new Scrollbar(Scrollbar.HORIZONTAL, 10, 0, 5, 100); //создание скроллбара с начальными параметрами
	sb.addAdjustmentListener(this); //регистрация приёмника
	p5.add(sb, BorderLayout.SOUTH); //добавление скроллбара на панель скрола
	p_right.add(p5, BorderLayout.SOUTH); //добавление панели на левую панель
	add(p_right); //добавление левой панели на фрейм
}

//реализация приёмника событий для радиокнопок
public void itemStateChanged(ItemEvent ie){
	flag = !flag; //изменение флага при нажатии радиокнопок
	if(!flag) { //выбрана функция Рисовать
		ch.setEnabled(false); //блокировка выбора шрифтов
		tf.setEnabled(false); //блокировка панели ввода текста
		sb.setEnabled(true); //разблокировка скроллбара
	} else { //выбрана функция Очистка
		ch.setEnabled(true); //разблокировка выбора шрифтов
		tf.setEnabled(true); //разблокировка панели ввода текста
		sb.setEnabled(false); //блокировка скроллбара
	}
	p_left.repaint(); //перерисовка канвы
}

//реализация приёмника событий от скроллбара
public void adjustmentValueChanged(AdjustmentEvent e) {
	sb_val = e.getValue(); //получение текущего значения скролбара
	p_left.repaint(); //перерисовка канвы
}
	
//реализация приёмника события от кнопок
public void actionPerformed(ActionEvent e){
acm = e.getActionCommand(); //получение имени нажатой кнопки
	//сравнение с существующими именами и выбор нужного действия
	if("розовый".equals(acm)) b1.setBackground(Color.pink);
	else if("синий".equals(acm)) b2.setBackground(Color.blue);
	else if("серый".equals(acm)) b3.setBackground(Color.gray);
	else if("зелёный".equals(acm)) b4.setBackground(Color.green);
	else if("фиолетовый".equals(acm)) b5.setBackground(Color.magenta);
	else if("голубой".equals(acm)) b6.setBackground(Color.cyan);
	else if("оранжевый".equals(acm)) b7.setBackground(Color.orange);
	else if("красный".equals(acm)) b8.setBackground(Color.red);
	else if("жёлтый".equals(acm)) b9.setBackground(Color.yellow);
	p_left.repaint();
}

public static void main(String args[]) {
final AnimBallsPlus panel = new AnimBallsPlus();
	Frame frame = new Frame("Успенская Т.А. ИВБ-111 Курсовая (без анимации)");
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
