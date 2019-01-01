
//import java.util.Scanner;
//import java.util.Stack;

/**
 *
 * @author Pujashree
 */
abstract class MyStack {

    public final void pushTemplateMethod() {
        show();
        push();
        display();
    }

    abstract protected void push();

    abstract protected void display();

    protected void show() {
        System.out.println("Stack implementation");
    }
}

