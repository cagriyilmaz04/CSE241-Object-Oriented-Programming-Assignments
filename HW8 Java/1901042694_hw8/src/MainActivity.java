
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class MainActivity implements ActionListener ,PegSolitaireGame,Cloneable{
    JFrame layout;
    Cell Undo;
    Cell Reset;
    Cell Save;
    Cell Load;
    Cell clone;
    Cell current = null;
    JLabel label1 ;
    int count = 0;
    int size=7;
    Cell firstBack;
    Cell secondBack;
    Cell thirdBack;
    int secondParameter;
    private JTextField fname;
    Cell[][] list = new Cell[7][7];
    Cell[][] arraylist = new Cell[10][10];
    int data;
    MainActivity(int a ,int b) {
        this.data = a;
        secondParameter=b;

        this.setAttributes();
    }
    @Override
   public void autoPlay(){
        int firstCell,secondCell;
        Cell data,data1;
        while (isItMove()){
            Random rand = new Random();
            int first= rand.nextInt(size);
            int second=rand.nextInt(size);
            firstCell=rand.nextInt(size);
            secondCell=rand.nextInt(size);
            int maxDirec=rand.nextInt(4);
            data=this.list[first][second];
            data1=this.list[firstCell][secondCell];
            if(data.getStatemet()!=Situation.SPACE&&data1.getStatemet()!=Situation.SPACE){
                if(maxDirec==0&&data.getXcoor()==data1.getXcoor()&&data.getStatemet()==Situation.PEG&&data1.getStatemet()==Situation.EMPTY&&data.getyCoor()-data1.getyCoor()==-2){
                    moveToTheRight(data,data1);
                    ++count;
                }
                else if(maxDirec==1&&data.getXcoor()==data1.getXcoor()&&data.getStatemet()==Situation.PEG&&data1.getStatemet()==Situation.EMPTY&&data.getyCoor()-data1.getyCoor()==2){
                    moveToTheLeft(data,data1);
                    ++count;
                }
                else if(maxDirec==2&&data.getyCoor()==data1.getyCoor()&&data.getStatemet()==Situation.PEG&&data1.getStatemet()==Situation.EMPTY&&data.getXcoor()-data1.getXcoor()==2){
                    moveToTheUp(data,data1);
                    ++count;
                }
                else if(maxDirec==3&&data.getyCoor()==data1.getyCoor()&&data.getStatemet()==Situation.PEG&&data1.getStatemet()==Situation.EMPTY&&data.getXcoor()-data1.getXcoor()==-2){
                    moveToTheDown(data,data1);
                    ++count;
                }
            }
        }
        label1.setText("Your result "+findScore());
        label1.setVisible(true);
        layout.add(label1);
        label1.setBounds(800,450,100,50);
    }
    @Override
    public int findScore(){
        int point=0;
        int i,j;
        for(i=0;i<size;++i){
            for(j=0;j<size;++j){
                if(list[i][j].getStatemet()==Situation.PEG){
                    ++point;
                }
            }
        }
        return point;
    }
    @Override
    public void show(){
        int i,j;
        int count=0;
        try {
            for(i=0;i<size;++i){
                for(j=0;j<size;++j){

                    if(list[i][j].getStatemet()==Situation.PEG){
                        layout.remove(list[i][j]);
                        layout.add(list[i][j]);
                        list[i][j].setText("X");
                    }else if(list[i][j].getStatemet()==Situation.EMPTY){
                        //layout.remove(list[i][j]);
                        layout.remove(list[i][j]);
                        layout.add(list[i][j]);
                        list[i][j].setText(" ");
                    }else{

                    }
                    layout.revalidate();
                    layout.repaint();
                    ++count;
                }
            }
        }catch (Exception e){}
    }
    @Override
    public void fillArray() {
        int i,j;
        if(data==1){
            size=7;
            for(i = 0; i < size; ++i) {
                for( j = 0; j < size; ++j) {
                    Cell temp;
                    if(i==0||i==6){
                        if(j==0||j==1||j==5||j==6){
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }else if(i==2||i==3||i==4){
                        if(i==2&&j==3){
                            temp=new Cell(i,j,Situation.EMPTY);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }else{
                        if(j==0||j==6){
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }
                }
            }
        }
        if(data==2){
            list= new Cell[9][9];
            arraylist=new Cell[9][9];
            size=9;
            for(i=0;i<size;++i){
                for(j=0;j<size;++j){
                    Cell temp;
                    if(i==3||i==4||i==5){
                        if(i==4&&j==4){
                            temp=new Cell(i,j,Situation.EMPTY);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }

                    }else{
                        if(j==3||j==4||j==5){
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);

                        }

                    }


                }
            }

        }
        if(data==3){
            list= new Cell[8][8];
            arraylist=new Cell[8][8];
            size=8;
            for(i=0;i<size;++i){
                for(j=0;j<size;++j){
                    Cell temp;
                    if(i==3||i==4||i==5){
                        if(i==4&&j==3){
                            temp=new Cell(i,j,Situation.EMPTY);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }else{
                        if(j==2||j==3||j==4){
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }
                }
            }
        }
        if(data==4){
            list= new Cell[7][7];
            arraylist=new Cell[7][7];
            size=7;
            for(i=0;i<size;++i){
                for(j=0;j<size;++j){
                    Cell temp;
                    if(i==2||i==3||i==4){
                        if(i==3&&j==3){
                            temp=new Cell(i,j,Situation.EMPTY);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }else{
                        if(j==2||j==3||j==4){
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }
                }
            }
        }
        if(data==5){
            list=new Cell[9][9];
            arraylist=new Cell[9][9];
            size=9;
            for(i = 0; i < size; ++i) {
                for( j = 0; j < size; ++j) {
                    Cell temp;
                    if(i==0||i==8){
                        if(j==4){
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }else if(i==1||i==7){
                        if(j==3||j==4||j==5){
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }else if(i==2||i==6){
                        if(j==2||j==3||j==4||j==5||j==6){
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }else if(i==3||i==5){
                        if(j==1||j==2||j==3||j==4||j==5||j==6||j==7){
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.SPACE);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }
                    else if(i==4){
                        if(j==0||j==1||j==2||j==3||j==5||j==6||j==7||j==8){
                            temp=new Cell(i,j,Situation.PEG);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }else{
                            temp=new Cell(i,j,Situation.EMPTY);
                            list[i][j]=temp;
                            arraylist[i][j]=temp;
                            temp.setBounds(j * 50, i * 50, 50, 50);
                            temp.addActionListener(this);
                        }
                    }
                }
            }
        }
    }
    @Override
    public void setAttributes() {
        this.layout = new JFrame("Peg Solitaire Game");
        label1=new JLabel();
        this.layout.setSize(1000, 1000);
        this.layout.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        clone=new Cell(-6,-6,Situation.NULL);
        clone.setBounds(800,300,100,50);
        clone.setText("Clone");
        layout.add(clone);
        clone.addActionListener(this);
        JLabel label = new JLabel("Enter the file name :");
        label.setBounds(800, 350, 150, 50);
        layout.add(label);
        this.layout.setLayout(null);
        this.layout.setVisible(true);
        this.Undo = new Cell(-1, -1, Situation.NULL);
        this.Undo.setBounds(800, 50, 100, 50);
        this.Undo.setText("Undo");
        this.Reset = new Cell(-2, -2, Situation.NULL);
        this.Reset.setBounds(800, 110, 100, 50);
        this.Reset.setText("Reset");
        this.Save = new Cell(-3, -3, Situation.NULL);
        this.Save.setBounds(800, 170, 100, 50);
        this.Save.setText("Save");
        this.Load = new Cell(-4, -4, Situation.NULL);
        this.Load.setBounds(800, 230, 100, 50);
        this.Load.setText("Load");
        fname = new JTextField() ;
        fname.setBounds(800, 410, 100, 50);
        layout.add(fname);
        this.layout.add(this.Undo);
        this.layout.add(this.Reset);
        this.layout.add(this.Save);
        this.layout.add(this.Load);
        this.Undo.addActionListener(this);
        this.Reset.addActionListener(this);
        this.Save.addActionListener(this);
        this.Load.addActionListener(this);

    }
    public void actionPerformed(ActionEvent e) {
        Cell temp= (Cell)((Cell)e.getSource());
        if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-1){
            if(firstBack!=null&&secondBack!=null&&thirdBack!=null){
                list[firstBack.getXcoor()][firstBack.getyCoor()].setStatemet(firstBack.getStatemet());
                list[secondBack.getXcoor()][secondBack.getyCoor()].setStatemet(secondBack.getStatemet());
                list[thirdBack.getXcoor()][thirdBack.getyCoor()].setStatemet(thirdBack.getStatemet());
                show();
            }
            count=0;
        }
        if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-2){
            int i,j;
            for(i=0;i<size;++i){
                for(j=0;j<size;++j){
                    layout.remove(list[i][j]);
                }
            }
            label1.setVisible(false);
            fillArray();
            show();
            count=0;
        }
        if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-3){
            if(fname.getText().length()==0){
                JOptionPane.showMessageDialog(layout, "You need to enter a file name.");
            }else{
                saveGame(fname.getText());
            }
            count=0;
        }
        if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-4){
            if(fname.getText().length()==0){
                JOptionPane.showMessageDialog(layout, "You need to enter a file name.");
            }else{
                loadGame(fname.getText());
            }
        }
        if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-6){
            System.out.println("Basıldı");
            try {
                Object clonedObject = (MainActivity)this.clone();

            }catch (Exception e1){

            }

        }

        else if (this.count == 0&&(temp.getStatemet()==Situation.PEG)) {
            this.current = (Cell)((Cell)e.getSource());
            ++this.count;
        } else if (this.count == 1&&temp.getStatemet()==Situation.EMPTY) {
            temp = (Cell)((Cell)e.getSource());
            count=0;
            if(isItMove()){
                if(current.getyCoor()==temp.getyCoor()){
                    if(current.getXcoor()>temp.getXcoor()){
                        System.out.println("//Move to the Up");
                        moveToTheUp(current,temp);
                    }else if(current.getXcoor()<temp.getXcoor()){
                        System.out.println("  //Move to the Down");
                        moveToTheDown(current,temp);
                    }
                }else if(current.getXcoor()==temp.getXcoor()){
                    if(current.getyCoor()>temp.getyCoor()&&current.getyCoor()-temp.getyCoor()==2){
                        System.out.println("//Move to the left");
                        moveToTheLeft(current,temp);
                    }else if(current.getyCoor()<temp.getyCoor()){
                        System.out.println("//Move to the Right");
                        moveToTheRight(current,temp);

                    }
                }
                if(!isItMove()){
                    label1.setText("Your result "+findScore());
                    label1.setVisible(true);
                    layout.add(label1);
                    label1.setBounds(800,450,100,50);
                    JOptionPane.showMessageDialog(layout, "The current game is finished");
                }
                current=null;
                temp=null;
                count=0;
            }

        }else if (this.count == 1&&temp.getStatemet()==Situation.PEG) {
           count=0;
            current=null;
        }
    }
    @Override
    public void loadGame(String text) {
        try {
            //getting properties
            File file = new File(text);
            Scanner sc = new Scanner(file);
           final int Size = sc.nextInt();
            int type = sc.nextInt();
            int i = 0;
            int j=0;
            list=new Cell[Size][Size];
            layout.dispose();
            this.setAttributes();
            show();
            data=type;
            size=Size;
            sc.nextLine();
            //getting coordinates queue
            int count=0;
            i=0;
            j=0;
            Cell[][] mainList= new Cell[Size][Size];
        while (sc.hasNextLine()!=false&count<Size*Size) {

                String line = sc.nextLine();
                String[] arr = line.split(" ");
                int row = Integer.parseInt(arr[0]);
                int column = Integer.parseInt(arr[1]);
                Situation str =Situation.SPACE;
                if(arr[2].equals("PEG")){
                 str=Situation.PEG;
                }
                if(arr[2].equals("SPACE")){
                    str=Situation.SPACE;
                }
                if(arr[2].equals("EMPTY")){
                    str=Situation.EMPTY;
                }
                Cell temp=new Cell(row,column,str);
             list[i][j]=temp;
                if(str!=Situation.SPACE){
                    list[i][j].setBounds(j * 50, i * 50, 50, 50);
                    list[i][j].addActionListener(this);
                    layout.add(list[i][j]);
                }
                ++j;
                if(j==Size){
                    j=0;
                    ++i;
                }
                ++count;
            }
        show();
            sc.close();
        }catch (IOException e) {
            e.printStackTrace();
        }

    }

    @Override
    public void saveGame(String fName){
        try {
            File file = new File(fName);
            if(!file.exists())
                file.createNewFile();
            //properties
            FileWriter fwriter = new FileWriter(file,true);
            fwriter.write(size+"\n");
            fwriter.write(data+"\n");
            int i,j;
            for(i=0;i<size;++i){
                for(j=0;j<size;++j){
                    fwriter.write(list[i][j].xcoor+" "+list[i][j].yCoor+" "+list[i][j].getStatemet()+"\n");
                }
            }
            fwriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    @Override
    public void moveToTheLeft(Cell first,Cell second){
        int x=first.getXcoor(),x1=second.getXcoor(),y=first.getyCoor(),y1=second.getyCoor();
        try {
            if(first.getStatemet()==Situation.PEG&&second.getStatemet()==Situation.EMPTY&&list[second.getXcoor()][second.getyCoor()+1].getStatemet()==Situation.PEG){
                firstBack=new Cell(x,y1,list[x][y1].getStatemet());
                firstBack.addActionListener(this);
                secondBack=new Cell(x,y1+1,list[x][y1+1].getStatemet());
                secondBack.addActionListener(this);
                thirdBack=new Cell(x,y1+2,list[x][y1+2].getStatemet());
                secondBack.addActionListener(this);
                arraylist[x][y1].setStatemet(Situation.PEG);;
                arraylist[x][y1+1].setStatemet(Situation.EMPTY);
                arraylist[x][y1+2].setStatemet(Situation.EMPTY);

                list[x][y1].setStatemet(Situation.PEG);
                list[x][y1+1].setStatemet(Situation.EMPTY);
                list[x][y1+2].setStatemet(Situation.EMPTY);
                show();
            }
        }catch (Exception e){

        }

    }
    @Override
    public void moveToTheRight(Cell first,Cell second){
        int x=first.getXcoor(),x1=second.getXcoor(),y=first.getyCoor(),y1=second.getyCoor();
        try {
            if(first.getStatemet()==Situation.PEG&&list[x][y+1].getStatemet()==Situation.PEG&&second.getStatemet()==Situation.EMPTY&&second.getyCoor()-first.getyCoor()==2){
                firstBack=new Cell(x,y,list[x][y].getStatemet());
                firstBack.addActionListener(this);
                secondBack=new Cell(x,y+1,list[x][y+1].getStatemet());
                secondBack.addActionListener(this);
                thirdBack=new Cell(x,y+2,list[x][y+2].getStatemet());
                secondBack.addActionListener(this);
                arraylist[x][y].setStatemet(Situation.EMPTY);
                arraylist[x][y+1].setStatemet(Situation.EMPTY);
                arraylist[x][y+2].setStatemet(Situation.PEG);

                list[x][y].setStatemet(Situation.EMPTY);
                list[x][y+1].setStatemet(Situation.EMPTY);
                list[x][y+2].setStatemet(Situation.PEG);
                show();
            }
        }catch (Exception e){

        }

    }
    @Override
    public   void moveToTheUp(Cell first,Cell second){
        int x=first.getXcoor(),x1=second.getXcoor(),y=first.getyCoor(),y1=second.getyCoor();
        try {
            if(first.getStatemet()==Situation.PEG&&this.list[x-1][y].getStatemet()==Situation.PEG&&second.getStatemet()==Situation.EMPTY&&second.getXcoor()-first.getXcoor()==-2){
                this.firstBack=new Cell(x,y1,list[x][y1].getStatemet());
                this.firstBack.addActionListener(this);
                this.secondBack=new Cell(x-1,y1,list[x-1][y1].getStatemet());
                this.secondBack.addActionListener(this);
                this.thirdBack=new Cell(x-2,y1,list[x-2][y1].getStatemet());
                this.secondBack.addActionListener(this);
                this.arraylist[x][y1].setStatemet(Situation.EMPTY);
                this.arraylist[x-1][y1].setStatemet(Situation.EMPTY);
                this.arraylist[x-2][y1].setStatemet(Situation.PEG);
                this.list[x][y1].setStatemet(Situation.EMPTY);
                this.list[x-1][y1].setStatemet(Situation.EMPTY);
                this.list[x-2][y1].setStatemet(Situation.PEG);
                show();
            }
        }catch (Exception e){

        }

    }
    @Override
    public boolean isItMove() {
        int i,j;
        boolean flag=false;
        for(i=0;i<list.length;++i){
            for(j=0;j<list[0].length;++j){
                if(j+2< list.length&&list[i][j].getStatemet()==Situation.EMPTY&&list[i][j+1].getStatemet()==Situation.PEG&&list[i][j+2].getStatemet()==Situation.PEG){
                    flag=true;
                    return flag;
                }
                if(j>=2&&list[i][j].getStatemet()==Situation.EMPTY&&list[i][j-1].getStatemet()==Situation.PEG&&list[i][j-2].getStatemet()==Situation.PEG){
                    flag=true;
                    return flag;
                }
                else if ((i < list.length - 2) && list[i][j].getStatemet() == Situation.EMPTY && list[i + 1][j].getStatemet() == Situation.PEG && list[i + 2][j].getStatemet() == Situation.PEG) {
                    flag = true;
                }
                else if ((i >= 2) && list[i][j].getStatemet() == Situation.EMPTY && list[i - 1][j].getStatemet() == Situation.PEG && list[i - 2][j].getStatemet() == Situation.PEG) {
                    flag = true;
                }
            }
        }
        return flag;
    }
    @Override
    public void moveToTheDown(Cell first,Cell second){
        int x=first.getXcoor(),x1=second.getXcoor(),y=first.getyCoor(),y1=second.getyCoor();
        try {
            if(first.getStatemet()==Situation.PEG&&list[x+1][y].getStatemet()==Situation.PEG&&second.getStatemet()==Situation.EMPTY&&second.getXcoor()-first.getXcoor()==2){
                firstBack=new Cell(x,y1,list[x][y1].getStatemet());
                firstBack.addActionListener(this);
                secondBack=new Cell(x+1,y1,list[x+1][y1].getStatemet());
                secondBack.addActionListener(this);
                thirdBack=new Cell(x+2,y1,list[x+2][y1].getStatemet());
                secondBack.addActionListener(this);
                arraylist[x][y1].setStatemet(Situation.EMPTY);
                arraylist[x+1][y1].setStatemet(Situation.EMPTY);
                arraylist[x+2][y1].setStatemet(Situation.PEG);
                list[x][y1].setStatemet(Situation.EMPTY);
                list[x+1][y1].setStatemet(Situation.EMPTY);
                list[x+2][y1].setStatemet(Situation.PEG);
                show();
            }
        }catch (Exception e){

        }
    }

    public Cell getCurrent() {
        return current;
    }

    public Cell getFirstBack() {
        return firstBack;
    }

    public Cell getSecondBack() {
        return secondBack;
    }

    public Cell getThirdBack() {
        return thirdBack;
    }

    public Cell[][] getList() {
        return list;
    }

    public void setList(Cell[][] list) {
        this.list = list;
    }

    public int getData() {
        return data;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public JTextField getFname() {
        return fname;
    }

    public void setFname(JTextField fname) {
        this.fname = fname;
    }

    public int getSecondParameter() {
        return secondParameter;
    }

    public void setSecondParameter(int secondParameter) {
        this.secondParameter = secondParameter;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        MainActivity Temp=new MainActivity(this.data,this.secondParameter);
        try {
            int i,j;
            Temp.fillArray();
            for(i=0;i<size;++i){
                for(j=0;j<size;++j){
                    Temp.list[i][j]= new Cell(i,j,list[i][j].getStatemet());
                    Temp.list[i][j].setBounds(50*j,50*i,50,50);

                    Temp.list[i][j].addActionListener(new ActionListener() {
                        @Override
                        public void actionPerformed(ActionEvent e) {
                            Cell temp= (Cell)((Cell)e.getSource());
                            if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-1){
                                if(Temp.firstBack!=null&&Temp.secondBack!=null&&Temp.thirdBack!=null){
                                    Temp.list[Temp.firstBack.getXcoor()][Temp.firstBack.getyCoor()].setStatemet(Temp.firstBack.getStatemet());
                                    Temp.list[Temp.secondBack.getXcoor()][Temp.secondBack.getyCoor()].setStatemet(Temp.secondBack.getStatemet());
                                    Temp.list[Temp.thirdBack.getXcoor()][Temp.thirdBack.getyCoor()].setStatemet(Temp.thirdBack.getStatemet());
                                    Temp.show();
                                }
                                Temp.count=0;
                            }
                            if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-2){
                                int i,j;
                                for(i=0;i<size;++i){
                                    for(j=0;j<size;++j){
                                        Temp.layout.remove(Temp.list[i][j]);
                                    }
                                }
                                Temp.label1.setVisible(false);
                                Temp.fillArray();
                                Temp.show();
                                Temp.count=0;
                            }
                            if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-3){
                                if(Temp.fname.getText().length()==0){
                                    JOptionPane.showMessageDialog(layout, "You need to enter a file name.");
                                }else{
                                    Temp.saveGame(Temp.fname.getText());
                                }
                                Temp.count=0;
                            }
                            if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-4){
                                if(Temp.fname.getText().length()==0){
                                    JOptionPane.showMessageDialog(layout, "You need to enter a file name.");
                                }else{
                                    Temp.loadGame(Temp.fname.getText());
                                }
                            }
                            if(temp.getStatemet()==Situation.NULL&&temp.getXcoor()==-6){
                                System.out.println("Basıldı");
                                try {
                                    Object clonedObject = (MainActivity)this.clone();

                                }catch (Exception e1){

                                }

                            }

                            else if (Temp.count == 0&&(temp.getStatemet()==Situation.PEG)) {
                                Temp.current = (Cell)((Cell)e.getSource());
                                ++Temp.count;
                            } else if (Temp.count == 1&&temp.getStatemet()==Situation.EMPTY) {
                                temp = (Cell)((Cell)e.getSource());
                                Temp.count=0;
                                if(isItMove()){
                                    if(Temp.current.getyCoor()==temp.getyCoor()){
                                        if(Temp.current.getXcoor()>temp.getXcoor()){
                                            System.out.println("//Move to the Up");
                                            Temp.moveToTheUp(Temp.current,temp);
                                        }else if(Temp.current.getXcoor()<temp.getXcoor()){
                                            System.out.println("  //Move to the Down");
                                            Temp.moveToTheDown(Temp.current,temp);
                                        }
                                    }else if(Temp.current.getXcoor()==temp.getXcoor()){
                                        if(Temp.current.getyCoor()>temp.getyCoor()&&Temp.current.getyCoor()-temp.getyCoor()==2){
                                            System.out.println("//Move to the left");
                                            Temp.moveToTheLeft(Temp.current,temp);
                                        }else if(Temp.current.getyCoor()<temp.getyCoor()){
                                            System.out.println("//Move to the Right");
                                            Temp.moveToTheRight(Temp.current,temp);

                                        }
                                    }
                                    if(!Temp.isItMove()){
                                        Temp.label1.setText("Your result "+findScore());
                                        Temp.label1.setVisible(true);
                                        Temp.layout.add(label1);
                                        Temp.label1.setBounds(800,450,100,50);
                                        JOptionPane.showMessageDialog(Temp.layout, "The current game is finished");
                                    }
                                    Temp.current=null;
                                    temp=null;
                                    Temp.count=0;
                                }

                            }else if (Temp.count == 1&&temp.getStatemet()==Situation.PEG) {
                                Temp.count=0;
                                Temp.current=null;
                            }
                        }
                    });
                }
            }
            Temp.count=0;
            Temp.show();

        }catch (Exception e){
            System.out.println(e.getLocalizedMessage());
        }

        return Temp;
    }


}
