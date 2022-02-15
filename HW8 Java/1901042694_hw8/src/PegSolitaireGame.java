public interface PegSolitaireGame {
    //Check the whether the game is suitable to play
    boolean isItMove();
    //Check and move and it depends on directions
    void moveToTheRight(Cell first,Cell second);
    void moveToTheLeft(Cell first,Cell second);
    void moveToTheUp(Cell first,Cell second);
    void moveToTheDown(Cell first,Cell second);
    //File operations
    void saveGame(String fName);
    void loadGame(String text);

    //Fill array as a our choice
    void fillArray();
    //Find the end of the game score
    int findScore();
    //Prints board
    void show();
    //Play the computer
    void autoPlay();
    //Create undo restart and other buttons
    void setAttributes();

}
