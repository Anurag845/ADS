import java.util.Scanner;

public class SLL implements commonList {

    Node start;
   
    int size;

    SLL() {
        start = null;
        size = 0;
    }

    public boolean isEmpty() {
        return start == null;
    }

    public void add(int val) {
        Node nptr = new Node(val, null);
        size++;
        if (start == null) {
            start = nptr;
           } else {
            Node temp=start;
            while(temp.link!=null)
                temp=temp.link;
            temp.link=nptr;
        }
    }
    public int size(){
        return size;
    }
    public void display(){
        System.out.print("\nSingly Linked List = ");
        if (size == 0) 
        {
        System.out.print("empty\n");
        return;
        }    
        if (start.link == null) 
        {
           System.out.println(start.data);
            return;
        }

        Node ptr = start;
        while (ptr.link != null)
        {
           System.out.print(ptr.data+ "->");
            ptr = ptr.link;
        }
        System.out.print(ptr.data+ "->");
    }
    
    @SuppressWarnings("resource")
    
	public static void main(String[] args)
    {   
        SLL sl=new SLL();
        Scanner sc=new Scanner(System.in);
        
        while (sc.hasNextInt())
        {
            int no=sc.nextInt();
            sl.add(no);
        }
        sl.display();
    }
}
