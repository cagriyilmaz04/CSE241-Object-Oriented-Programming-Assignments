//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by FernFlower decompiler)
//

import javax.swing.JButton;

public class Cell extends JButton {
    int xcoor;
    int yCoor;
    Situation statemet;
        //Cell for each button
    public Cell(int xCoor, int yCoor, Situation state) {
        this.xcoor = xCoor;
        this.yCoor = yCoor;
        this.statemet = state;
        JButton data = new JButton();
        data.setVisible(true);
    }

    public void setXcoor(int xcoor) {
        this.xcoor = xcoor;
    }

    public void setyCoor(int yCoor) {
        this.yCoor = yCoor;
    }

    public void setStatemet(Situation statemet) {
        this.statemet = statemet;
    }

    public int getXcoor() {
        return this.xcoor;
    }

    public int getyCoor() {
        return this.yCoor;
    }

    public Situation getStatemet() {
        return this.statemet;
    }
}
