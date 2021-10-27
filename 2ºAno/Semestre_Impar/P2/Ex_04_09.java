import java.util.Locale;
import java.util.Scanner;
import java.text.NumberFormat;

class Circle {
  
    private double radius = 0;
    private double area = 0;
    private double perimeter = 0;

    public void setRadius(double x) {
        this.radius = x;
    }

    public Circle(double radius) {
        setRadius(radius);
    }

    public void setArea(double y) {
        this.area =  Math.pow(Math.PI * radius, 2);
    }

    public double getArea() {
        return area;
    }

    public void setPerimeter(double z) {
        this.perimeter = 2 * Math.PI * radius;
    }

    public double getPerimeter() {
        return perimeter;
    }

}

public class Ex_04_09 {
    public static void main(String[] args) {
        // Input
        Scanner s = new Scanner(System.in);
        double r1 = s.nextDouble();
        double r2 = s.nextDouble();
        s.close();
        
        // Calc
        Circle c1 = new Circle(r1);
        Circle c2 = new Circle(0);
        c2.setRadius(r2);
        //
        double area = c1.getArea() - c2.getArea();
        double p1 = c1.getPerimeter();
        double p2 = c2.getPerimeter();
        // Output
        NumberFormat nf = NumberFormat.getInstance(Locale.US);
        nf.setMinimumFractionDigits(2);
        nf.setMaximumFractionDigits(2);
        System.out.println(nf.format(area) + " " + nf.format(p1) + " " + nf.format(p2));
    }
}
