import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.NoSuchElementException;

public class ExercisePets 
{
    public static void main(String[] args) {
        List<Pet> pets = new ArrayList<Pet>();
        Scanner s = new Scanner(System.in);

        String line = new String();

        try 
        {
            while((line = s.nextLine()) != null) 
            {
                try {
                    if (line.substring(0, 2).equals("d ") || line.substring(0, 2).equals("c ")) 
                    {
                        if (line.substring(0, 1).equals("d")) {
                            Dog dog = new Dog(line.substring(2, line.indexOf("|")));
                            try {
                                int number = Integer.parseInt(line.substring(line.indexOf("|")) + 2);
                                dog.setWeight(number);
                                pets.add(dog);
                                System.out.println("OK");
                            } catch (NumberFormatException e) {
                                System.out.println("ERR");
                            }
                        } else {
                            Cat cat = new Cat(line.substring(2, line.indexOf("|")));
                            cat.setCoatColor(line.substring(line.indexOf("|") + 1));
                            pets.add(cat);
                            System.out.println("OK");
                        }
                    } else {
                        System.out.println("ERR");
                    }
                } catch (StringIndexOutOfBoundsException e) {
                    System.out.println("ERR");
                }
            }
        } catch (NoSuchElementException e) {
            s.close();

            for (var x: pets) {
                System.out.println(x.toString());
            }
        }
    }
}