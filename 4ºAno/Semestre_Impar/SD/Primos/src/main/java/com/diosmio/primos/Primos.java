public class Primos {
    int start, end;
    
    public Primos(int start, int end) {
        this.start = start;
        this.end = end;
    }
    
    private boolean ePrimo(int x) {
        if(x == 0 || x == 1) return false;
        
        for(int i = 2; i < x; i++) {
            if(x % i == 0) return false;
        }
        
        return true;
    }
    
    private int contaPrimos() {
        int primos = 0;
        for(int i = start; i <= end; i++) {
            if(ePrimo(i)) primos++;
        }
        
        return primos;
    }
    
    public void go() {
        System.out.println(contaPrimos());
    }

    public static void main(String[] args) {
        Primos a = new Primos(0, 50000);
        Primos b = new Primos(50000, 100000);
        Primos c = new Primos(100000, 150000);
        Primos d = new Primos(150000, 200000);
        
        a.go();
        b.go();
        c.go();
        d.go();
    }
}
