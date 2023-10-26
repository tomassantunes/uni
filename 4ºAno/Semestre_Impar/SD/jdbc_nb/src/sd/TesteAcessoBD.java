package sd;

import java.io.FileInputStream;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Properties;

/**
 *
 * @author jsaias
 */
public class TesteAcessoBD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {

        // coloque os argumentos
        
        // PostgresConnector pc = new PostgresConnector( ?? );
        // NOTA: não DEVE ter configuracoes no código fonte!!!
        // passar como argumento ou ler de .properties
        Properties p = new Properties();
        p.load(new FileInputStream("config.properties"));
        
        String host = p.getProperty("db.host");
        String db = p.getProperty("db.db");
        String user = p.getProperty("db.user");
        String pw = p.getProperty("db.pw");
        
        PostgresConnector pc = new PostgresConnector(host, db, user, pw);

        
        
        // estabelecer a ligacao ao SGBD
        pc.connect();
        Statement stmt = pc.getStatement();

	// *******************
        // update/insert
        try {

           // AQUI: operação para inserir um registo com o seu nome...

        } catch (Exception e) {
            e.printStackTrace();
            System.err.println("Problems on insert...");
        }

	// ******************
        // query	
        try {
            
            // AQUI: código para realizar a CONSULTA
            stmt.executeQuery("INSERT INTO personl48511 VALUES (1, 'Aquele ali', '1530-01-01 03:00:00')");
            
        } catch (Exception e) {
            e.printStackTrace();
            System.err.println("Problems retrieving data from db...");
        }

        // desligar do SGBD:
        pc.disconnect();
    }


}
