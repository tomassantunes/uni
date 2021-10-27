public class Temperature {

    private double celsius = 0.0;

    public void setCelsius(double celsius) {
        this.celsius = celsius;
    }

    public double toCelsius() {
        return celsius;
    }

    public void setFahrenheit(double fahr) {
        setCelsius((fahr - 32) / 1.8);
    }
    
    public double toFahrenheit() {
        return 1.8 * celsius + 32;
    }

    public static void main(String[] args) {
        Temperature temp = new Temperature();

        temp.setCelsius(0);
        System.out.println("0ºC" + temp.toFahrenheit() + " ºF");
    }

}
