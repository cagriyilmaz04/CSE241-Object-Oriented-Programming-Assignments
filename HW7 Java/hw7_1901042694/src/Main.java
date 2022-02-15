import java.util.ArrayList;

public class Main {
    public Main() {

    }

    public static void main(String[] args) {
        DayofYearSet list1 = new DayofYearSet();
        DayofYearSet list2 = new DayofYearSet();
        DayofYearSet.DayofYear datas = new DayofYearSet.DayofYear(6, 7);
        DayofYearSet.DayofYear datas1 = new DayofYearSet.DayofYear(8, 7);
        DayofYearSet.DayofYear datas2 =new DayofYearSet.DayofYear(7,6);
        list1.add(datas1);
        list1.add(datas);
        list1.add(datas2);
        list2.add(datas1);
        list2.add(datas2);
        list2.writeToFile("cagri.txt");

        System.out.println(list2.toString());
        list2.delete(datas1);
        DayofYearSet newDatas = new DayofYearSet();
        newDatas =list1.setUnion(list2);
        newDatas = newDatas.setComplement();
        System.out.println(newDatas.getSize());
        System.out.println(list1.getList()[0].toString());
        list2=list2.setComplement();
        list1=list1.setComplement();
        list1=list1.setIntersection(list2);
        if(list1.equals(newDatas)){
            System.out.println("De morgan rule is working");
        }

        ArrayList<DayofYearSet.DayofYear> newDayofYear=new ArrayList<DayofYearSet.DayofYear>();
        newDayofYear.add(datas);
        newDayofYear.add(datas2);
        newDayofYear.add(datas1);
        DayofYearSet Const= new DayofYearSet(newDayofYear);
        System.out.println(Const.toString());
        System.out.println("\n Active object "+ DayofYearSet.totalAlive());

    }

}


