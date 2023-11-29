package spring.boot.security.jdbc.auth.config;

import javax.sql.DataSource;
import org.springframework.beans.factory.annotation.Autowired;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.env.Environment;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.DriverManagerDataSource;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabase;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseBuilder;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseType;

//@Configuration
//public class DatabaseConfig {

//	@Bean
//	public DataSource dataSource() {
//		EmbeddedDatabaseBuilder builder = new EmbeddedDatabaseBuilder();
//		EmbeddedDatabase db = builder.setType(EmbeddedDatabaseType.H2) // .H2 or .DERBY, etc.
//				.addScript("user.sql").addScript("user-role.sql").build();
//		return db;
//	}

//}

@Configuration
public class DatabaseConfig {
    // from application.properties
    @Autowired
    Environment environment;
    private final String URL =      "spring.datasource.url";
    private final String USER =     "spring.datasource.username";
    private final String DRIVER =   "spring.datasource.driver-class-name";
    private final String PASSWORD = "spring.datasource.password";
    
    @Bean
    public DataSource dataSource() {
            DriverManagerDataSource driverManagerDataSource = new DriverManagerDataSource();
            driverManagerDataSource.setUrl(environment.getProperty(URL));
            driverManagerDataSource.setUsername(environment.getProperty(USER));
            driverManagerDataSource.setPassword(environment.getProperty(PASSWORD));
            driverManagerDataSource.setDriverClassName(environment.getProperty(DRIVER));
            return driverManagerDataSource;
    }    
        
    @Bean
    public JdbcTemplate jdbcTemplate() {
        return new JdbcTemplate(dataSource());
    }        
}