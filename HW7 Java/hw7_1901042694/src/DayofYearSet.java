import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
public class DayofYearSet{
    /*
       *Inner class
     */
    public static class DayofYear{
        private int day;
        private int month;
        public DayofYear(int Day, int Month) {
            this.day = Day;
            this.month = Month;
            ++alive;
        }
        public DayofYear() {}
        public int getDay() {
            return this.day;
        }
        public int getMonth() {
            return this.month;
        }
        public void setAlive(int Alive){alive=Alive;}
        public int getAlive(){ return alive;}
        public void setDay(int day) {
            this.day = day;
        }
        public void setMonth(int month) {
            this.month = month;
        }
        @Override
        public String toString() {
            return "DayofYear{" + "day=" + day + ", month=" + month + '}';
        }

    }
    /*
     *Constructors;
     */
    public DayofYearSet() {}
    public DayofYearSet(ArrayList<DayofYear> data) {
        //Casting our parameter as a array
            list= data.toArray(new DayofYear[0]);
            used=data.size();

    }
    /*
    *Getter and Setter
     */
    public DayofYear[] getList() {
        return this.list;
    }
    public void setList(DayofYear list[] ) {
        this.list = list;
    }
    public void setData(DayofYearSet.DayofYear data) {
        this.data = data;
    }
    public DayofYearSet.DayofYear getData() {
        return this.data;
    }
    public int getSize(){return used;}
    public void setSize(int newSize){used=newSize;}
    /*
     *Main Methods
     */
    public void delete(DayofYear item) {
        int index=findIndex(item);
        int size=used;
        if(checkInput(item.getDay(),item.getMonth())){
            DayofYear[] newList = new DayofYear[used];
            if(index!=-1){
                int i=0,j=0;
                while(i<used){
                    if(i!=index){
                        newList[j]=list[i];
                        ++j;
                    }
                    ++i;
                }
                System.out.println(j+" Size");
                setList(newList);
                setSize(j);
            }
        }
    }

    /*
     *To find difference between two objects
     */
    public DayofYearSet setDifference(DayofYearSet other){
        DayofYearSet newList=new DayofYearSet();
        var size=list.length;
        int i;
        for(i=0;i<size;++i){
            if(!duplicate(other.list,list[i])){
                newList.add(list[i]);
            }
        }
        return newList;
    }
    /*
    *Add an item to DayofYearSet Object
    *First off all , We check input and used if used is less than or equal 1 we do not have to check whether the item is duplicated or not.
     */
    public void add(DayofYear item) {
        if(checkInput(item.getDay(),item.getMonth())){
            if(used!=0){
                if (!this.duplicate(this.list,item)) {
                    this.data.day = item.day;
                    this.data.month = item.month;
                    this.list[used]=item;
                    ++used;

                }
            }else{

                this.data.day = item.day;
                this.data.month = item.month;
                this.list[used]=item;
                ++used;
            }
        }
    }
    /*
        *Static function that counts all alive DayofYear object;
     */
    public static int totalAlive(){return alive;}
    /*
    *This function finds whether these 2 objects are equal or not without looking order;
     */
    public boolean equals(DayofYearSet other) {
        var size=this.used;
        var size2=other.used;
        int i,j;
        int count=0;
        var flag=false;
        if(size==size2){
            for(i=0;i<size;++i){
                for(j=0;j<size2;++j){
                    if(equalData(list[i],other.list[j])){
                        flag=true;
                        ++count;
                    }
                }
            }
            if(count==size){
                flag=true;
            }else{
                flag=false;
            }
        }
        return flag;
    }

    public DayofYearSet setComplement(){
        DayofYearSet cagri=new DayofYearSet();
        DayofYear[] returnedValue=setDayOfYearList();
        int i,j=0;
        boolean flag=false;
        int index=0;
        for(j=0;j<365;++j){
            for(i=0;i<used;++i){
                if(equalData(list[i],returnedValue[j])){
                    flag=true;
                    i=used;
                }
            }
            if(flag){
                ++index;
                flag=false;
            }else{
                cagri.add(returnedValue[j]);
            }
        }
        cagri.setSize(365-index);
        cagri.setList(cagri.list);
        return cagri;

    }
    /*
    *Helper Functions
    * This function controls that two DayofYearSet objects are equal or not
    * This function prevents an item adds at least two times
     */
    public boolean duplicate(DayofYear List[] , DayofYear element) {
        int i ;
        boolean flag = false;

        for(i = 0; i < getSize(); ++i) {
            if (this.equalData(List[i], element)) {
                flag = true;
                break;
            }
            flag = false;

        }
        return flag;
    }
    /*
    *This function prevents to enter wrong input;
     */
    public boolean checkInput(int day,int month){
        boolean flag=false;
        if(month==1){
            if(day>=1&&day<=31){
                flag=true;
            }
        }
        if(month==2){
            if(day>=1&&day<=28){
                flag=true;
            }
        }
        if(month==3){
            if(day>=1&&day<=31){
                flag=true;
            }
        }

        if(month==4){
            if(day>=1&&day<=30){
                flag=true;
            }
        }
        if(month==5){
            if(day>=1&&day<=31){
                flag=true;
            }
        }
        if(month==6){
            if(day>=1&&day<=30){
                flag=true;
            }
        }
        if(month==7){
            if(day>=1&&day<=31){
                flag=true;
            }
        }
        if(month==8){
            if(day>=1&&day<=31){
                flag=true;
            }
        }
        if(month==9){
            if(day>=1&&day<=30){
                flag=true;
            }
        }
        if(month==10){
            if(day>=1&&day<=31){
                flag=true;
            }
        }
        if(month==11){
            if(day>=1&&day<=30){
                flag=true;
            }
        }
        if(month==12){
            if(day>=1&&day<=31){
                flag=true;
            }
        }
        return flag;
    }
    /*
     *This function controls two DayOfyear items are equal or not
     */
    public boolean equalData(DayofYearSet.DayofYear item, DayofYearSet.DayofYear item1) {
        return item1.day == item.day && item1.month == item.month;
    }
    /*
     *These function eases to find index that wants to remove an item from list;
     */
    public int findIndex(DayofYear item){
        int index=-1;
        for(int i = 0; i < this.list.length; ++i) {
            if (this.equalData((DayofYearSet.DayofYear)this.list[i], item)) {
                index=i;
                break;
            }
        }
        return index;
    }
    /*
     *This function adds a DayofYearSet object to the other object
     */
    public DayofYearSet setUnion(DayofYearSet other) {
        int size2=other.getSize();
        System.out.println(size2);
        int j;
        for(j=0;j<size2;++j){
            if(!duplicate(this.list,other.list[j])){
                add(other.list[j]);

            }
        }
        return this;
    }
    /*
     *To find the common item
     */
    public DayofYearSet setIntersection(DayofYearSet other){
        DayofYearSet returnedValue=new DayofYearSet();
        int size=other.used;

        if(used> other.used){
            size=used;
        }
        int i;
        for(i=0;i< other.used;++i){
            if(duplicate(this.list,other.getList()[i])){
                returnedValue.add(other.getList()[i]);
            }
        }
        return returnedValue;
    }
    /*
     *This function needs to complement list because we need to make an array that holds all days of year it returns a list that has all days of year;
     */
    public DayofYear[] setDayOfYearList(){
        DayofYear[] list = new DayofYear[365] ;
        int i=1,j=1;
        int index=0;
        for(i=1;i<=12;++i){
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                for(j=1;j<=31;++j){
                    DayofYear data=new DayofYear(j,i);
                    list[index]=data;
                    ++index;
                }
            }
            if(i==4||i==6||i==9||i==11){
                for(j=1;j<=30;++j){
                    DayofYear data=new DayofYear(j,i);
                    list[index]=data;
                    ++index;
                }
            }
            if(i==2){
                for(j=1;j<=28;++j){
                    DayofYear data=new DayofYear(j,i);
                    list[index]=data;
                    ++index;
                }
            }
            j=1;
        }
        return list;
    }
    void writeToFile(String fileName){
        try {
            File myObj = new File(fileName);
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName()+"\n");
            } else {

                System.out.println("File already exists.");
            }
            try {
                int i;
                FileWriter writer = new FileWriter(fileName);
                writer.write("Day\t"+"Month\n");
                for(i=0;i<used;++i){
                    writer.write(" "+list[i].getDay()+"\t"+list[i].getMonth()+" \n");
                }
                writer.write("Active Games "+alive);
                writer.close();
                System.out.println("Successfully wrote to the file.");
            } catch (IOException e) {
                System.out.println("Error");
                e.printStackTrace();
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
    /*
       *To write details about DayofYearSet Objects;
     */
    @Override
    public String toString() {
        StringBuilder returnedValue= new StringBuilder();
        returnedValue.append("Size "+used+"\n");
        int i;
        for(i=0;i<used;++i){
            returnedValue.append("Day: "+list[i].day+" Month "+list[i].month+" \n");
        }
        return returnedValue.toString();
    }
    /*
     *Field
     */
    private DayofYear[] list = new DayofYear[365] ;
    private DayofYearSet.DayofYear data = new DayofYearSet.DayofYear();
    private int size=0;
    /*
     *How many item that we put into the object;
     */
    private int used=0;
    /*
     *To find that how many DayofYear objects are alive
     */
    private static int alive=0;
}