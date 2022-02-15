//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by FernFlower decompiler)
//

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class MyFrame extends JFrame implements ActionListener {
    JCheckBox first;
    JCheckBox second;
    JCheckBox third;
    JCheckBox fourth;
    JCheckBox fifth;
    JCheckBox type1;
    JCheckBox type2;
    JButton submit;
    int data = 0;
    int newData=0;
    JFrame frame;
    MyFrame() {
        //Make our view components
          frame = new JFrame();
         submit = new JButton("Let's Go");
        first= new JCheckBox("1");
        second= new JCheckBox("2");
        third= new JCheckBox("3");
        fourth= new JCheckBox("4");
        fifth= new JCheckBox("5");
        frame.add(first);
        frame.add(second);
        frame.add(third);
        frame.add(fourth);
        frame.add(fifth);
        frame.add(submit);
        final ButtonGroup bg = new ButtonGroup();
         type1 = new JCheckBox("User");
         type2 = new JCheckBox("Computer");
        JLabel label1 = new JLabel("Choose a game");
        JLabel label2 = new JLabel("Choose the type of game :");
        first.setBounds(50,55,50,30);
        second.setBounds(100,55,50,30);
        third.setBounds(150,55,50,30);
        fourth.setBounds(200,55,50,30);
        fifth.setBounds(250,55,50,30);
        label1.setBounds(50, 20, 200, 30);
        first.addActionListener(this);
        second.addActionListener(this);
        third.addActionListener(this);
        fourth.addActionListener(this);
        fifth.addActionListener(this);
        type1.addActionListener(this);
        type2.addActionListener(this);
        label2.setBounds(50, 80, 200, 30);
        type1.setBounds(50, 110, 150, 40);
        type2.setBounds(50, 150, 150, 50);

        submit.setBounds(200, 200, 150, 50);
        submit.addActionListener(this);
        bg.add(type1);
        bg.add(type2);
        frame.add(label1);
        frame.add(label2);
        frame.add(type1);
        frame.add(type2);
        frame.add(submit);

        frame.setSize(400,350);
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        frame.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==this.type1){
            this.newData=1;
        }
        if(e.getSource()==this.type2){
            this.newData=2;
        }
        if (e.getSource() == this.first) {
            this.data = 1;
        } else if (e.getSource() == this.second) {
            this.data = 2;
        } else if (e.getSource() == this.third) {
            this.data = 3;
        }
        else if (e.getSource() == this.fourth) {
            this.data = 4;
        }
        else if (e.getSource() == this.fifth) {
            this.data = 5;
        }

        else if (e.getSource() == this.submit) {
            //To check whether user chooses or not
            if (data != 0&&newData!=0) {
                frame.dispose();
                MainActivity first= new MainActivity(data,newData);
                first.fillArray();
                first.show();
                if(newData==2){
                    first.autoPlay();
                }
            } else {
                JOptionPane.showMessageDialog(frame, "You need to choose a type and who plays the game");
            }
        }

    }

    public static void main(String[] args) {
        MyFrame ff = new MyFrame();


    }
}
