import java.util.*;

public class ADSL_JavaDS {

    public static void main(String[] args) {

    	Vector v = new Vector();
        Stack s = new Stack();
        ArrayList al = new ArrayList();
        LinkedList ll = new LinkedList();
        Iterator itr;

        Entry e1 = new Entry("Apple","Fruit");
        Entry e2 = new Entry("Ball","Toy");
        Entry e3 = new Entry("Cat","Animal");
        Entry e4 = new Entry("doll","toy");
        int cont;
        do {
            System.out.println("1.Vector\n2.ArrayList\n3.LinkedList\n4.Stack\n5.HashMap");
            System.out.println("Enter the choice:");
            Scanner sc = new Scanner(System.in);
            int ch = sc.nextInt();
            switch (ch) {
                case 1:
                    v.addElement(e1);
                    v.addElement(e2);
                    v.addElement(e3);
                    v.addElement(e4);
                   
                    Enumeration vEnum = v.elements();
                    System.out.println("\nElements in vector:");
                    while (vEnum.hasMoreElements()) {
                        ((Entry) vEnum.nextElement()).display();
                    }
                    System.out.println("Capacity: " + v.capacity() + " Size :" + v.size());
                    break;
                case 2:
                    al.add(e1);
                    al.add(e2);
                    al.add(e3);
                    
                    itr = al.iterator();
                    while (itr.hasNext()) {
                        ((Entry) itr.next()).display();
                    }
                    if (al.contains(e1)) {
                        System.out.println("Found");
                    }
                    break;
                case 3:
                    ll.add(e1);
                    ll.add(e2);
                    ll.add(e3);
                    itr = ll.iterator();
                    while (itr.hasNext()) {
                        ((Entry) itr.next()).display();
                    }
                    if (ll.contains(e1)) {
                        System.out.println("Found");
                    }
                    break;
                case 4:
                    s.push(e1);
                    s.push(e2);
                    s.push(e3);
                    while (!s.empty()) {
                        Entry e = (Entry) s.pop();
                        e.display();
                    }
                    break;
                case 5:
                    HashMap<String, String> hm = new HashMap<String, String>();
                    hm.put("Apple", "Fruit");
                    hm.put("Ball", "Toy");
                    hm.put("Cat", "Animal");
                    for (Map.Entry m : hm.entrySet()) {
                        System.out.println(m.getKey() + " " + m.getValue());
                    }
                    if(hm.containsKey("Apple"))
                        System.out.println("Apple Found");
                    
                    break;
            }
            System.out.println("Do you want to continue(1/0):");
            cont = sc.nextInt();
        } while (cont == 1);
    }
}
