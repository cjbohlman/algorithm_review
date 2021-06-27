import java.util.Hashtable;
import java.util.Enumeration;

public class HashMap {
    private Hashtable<String, String> table;

    public HashMap() {
        table = new Hashtable<String, String>();
    }

    public void add(String key, String value) {
        table.put(key, value);
    }

    public void remove(String key) {
        table.remove(key);
    }

    public boolean exists(String key) {
        return table.containsKey(key);
    }

    public String get(String key) {
        return table.get(key);
    }

    public int getSize() {
        return table.size();
    }

    public static void asserting(boolean assertion) {
        if (!assertion) throw new RuntimeException();
    }

    public void print_table() {
        System.out.println("Printing hash table:");
        System.out.println("---------------------------");

        Enumeration<String> e = table.keys();
        while(e.hasMoreElements()) {
            String key = e.nextElement();
            System.out.println("Key: "+key+", value: "+get(key));
            System.out.println("---------------------------");
        }
    }

    public static void main(String args[]) {
        HashMap table = new HashMap();

        asserting(!table.exists("asfdf"));
        asserting(table.getSize() == 0);
        table.print_table();

        table.add("1", "one");
        asserting(table.getSize() == 1);
        asserting(table.exists("1"));
        asserting(!table.exists("2"));
        table.print_table();

        table.add("2", "two");
        table.add("3", "three");
        table.add("4", "four");
        asserting(table.getSize() == 4);
        asserting(table.exists("4"));
        asserting(table.exists("3"));
        asserting(table.exists("2"));
        table.print_table();

        asserting(table.get("1") == "one");
        asserting(table.get("2") == "two");
        asserting(table.get("3") == "three");
        asserting(table.get("4") == "four");
        asserting(table.get("5") == "");

        table.add("4", "cuatro");
        asserting(table.get("1") == "one");
        asserting(table.get("2") == "two");
        asserting(table.get("3") == "three");
        asserting(table.get("4") == "cuatro");
        asserting(table.get("5") == "");
        table.print_table();

        table.remove("1");
        asserting(!table.exists("1"));
        asserting(table.get("1") == "");
        asserting(table.get("2") == "two");
        asserting(table.get("3") == "three");
        asserting(table.get("4") == "cuatro");
        asserting(table.get("5") == "");
        asserting(table.getSize() == 3);
        table.print_table();

        table.add("5", "five");
        table.add("6", "six");
        table.add("7", "seven");
        table.add("8", "eight");
        asserting(table.exists("3"));
        asserting(table.exists("5"));
        asserting(!table.exists("9"));
        asserting(table.getSize() == 7);
        table.print_table();
        table.add("9", "nine");
        table.print_table();
        asserting(table.getSize() == 8);
        asserting(!table.exists("1"));
        asserting(table.exists("5"));
        asserting(table.exists("9"));

        table.print_table();

        table.remove("2");
        table.remove("3");
        table.remove("4");
        asserting(table.getSize() == 5);
        table.print_table();
        table.remove("5");
        asserting(table.getSize() == 4);
        table.print_table();


        HashMap table2 = new HashMap();
        asserting(table2.getSize() == 0);
        table2.add("one", "one");
        table2.add("noe", "two");
        table2.add("eon", "three");
        asserting(table2.getSize() == 3);
        table2.print_table();

        table2.remove("noe");
        asserting(table2.getSize() == 2);
        asserting(table2.exists("eon"));
        table2.add("eon", "four");
        table2.print_table();
        asserting(table2.getSize() == 2);
        asserting(table2.get("eon") == "four");
        asserting(!table2.exists("noe"));
    }
}