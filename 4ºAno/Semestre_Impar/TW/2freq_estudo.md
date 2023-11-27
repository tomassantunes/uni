# Resolução de Freq

### 1.
Como começar um form?

R: Para criar um form em HTML, começamos por abrir uma tag <form>.

### 2.
Componente de um formulário que deixa escolher só uma opção (atenção) entre 3 opções (ÁGUA, CHÁ E REFRIGERANTE)?

R: O componente de um formulário que permite escolher uma só opção entre várias opções, é o componente *radio*.

### 3.
Alterar código:

1. COMO ATIVAR UMA FUNÇÃO -> ONCLICK
R: 
Botão:
```javascript
document.getElementById("button").addEventListener("click", function() {});
```

```javascript
$("#button").on("click", function() {});
```

window:
```javascript
function hello() {
    console.log("Hello world");
}

window.onclick = hello;
```

2. O QUE ESTÁ NO DIV -> APARECER NO LOG
```javascript
console.log(document.getElementsByTagName("div")[0].innerHTML);
```

### 4.
Aplicação convencional VS SPA (single page app).

R: Uma aplicação convencional é uma aplicação em que a maior parte da lógica é tratada pelo servidor, e em que a maioria das interações com o browser desencadeiam um pedido de HTTP ao servidor que devolve uma nova página. Enquanto que uma Single Page App, é um tipo de aplicação em que a maior parte das interações ocorrem do lado do cliente, sendo que a comunicação com o servidor é feita através de serviços REST, e são maioritariamente para obtenção de dados. De forma a que não sejam necessários fazer pedidos HTTP para obter a página, quando o utilizador entra na página o browser descarrega todo o código da aplicação.

### 5.
Alterar código javascript, apresentar soma de conteúdo de um array numa alert box.
```javascript
function sumArr(arr) {
    let sum = 0
    for(x of arr) {
        sum += x
    }

    return sum
}

let arr = [1, 2, 3, 4, 5]
alert(sumArr(arr));
```

# Notas
- **Comunicação síncrona** - ao efetuar um pedido a execução fica suspensa até a resposta chegar.
- **Comunicação assíncrona** - ao efetuar um pedido a execução pode continuar de imediato, e a resposta será tratada quando e se chegar.

- XMLLHttpRequest
    - Objeto usado em JS na comunicação com servidores, nomeadamente para obter dados.
    - Flexível pois permite:
        - Atualizar apenas parte da página.
        - Solicitar dados ao servidor.
        - Receber dados do servidor.
        - Enviar dados ao servidor em background.

- AJAX
    - Abordagem que combina HTML, CSS, JS, DOM, XML, XSTL e XMLHttpRequest para troca de dados e atualização parcial e incremental da interface.

- Abordagem clássica: um pedido => carregar documento inteiro.
- Aborbagem AJAX: um pedido => atualizar apenas o necessário conforme a resposta recebida.

- Promise Object: representa o estado de execução consumada, ou de falha, de uma operação assíncrona.

- Web worker: permite execução em Thread separada, útil para operações demoradas.

- Push notifications: comunicações servidor -> browser.
    - Mesmo sem interação do utilizador com o browser, há um canal onde o servidor pode escrever, no momento em que for oportuno, e esses dados chegam ao browser e permitem atualizar automaticamente uma interface.

- Armazenamento junto ao browser
    - Permite o apoio a operações de recolha gradual de dados.
    - Reduz a frequência de pedidos ao servidor.
    - Permite guardar o estado da aplicação em caso de problemas de rede ou acesso intermitente.
    - Suporte a progressive webapps

- Soluções
    - Cache API
        - guarda pedidos e respetivas respostas, para reutilização posterior e ganho de eficiência.
    - Indexed DB
        - armazenamento persistente de dados estruturados, com indexação.
    - AlaSQL
        - BD que funciona no browser, em memória.

- Vizualização de dados
    - Representação gráfica de dados e de informação.
    - Pode ser interativa.
    - Pode assentar em tabelas, ou ter apenas elementos gráficos de leitura rápida.
    - Raw Data -> Data Tables -> Visual Structures -> Visualization
    - Em WebApps, requisitos:
        - Dados
        - Biblioteca para desenhar gráficos (Plotly.js, Frappe Charts, Chart.js, D3.js)

- Dashboard
    - Relatório gráfico, compacto, que resume visualmente os indicadores-chave.
    - Ferramentas analíticas, interativas, permitem explorar, mudar a perspetiva.
    - Cuidado com ecrãs pequenos: não deixar de fora nenhum indicador-chave que obrigue a deslizar/navegar para ler

- Aplicações web (site)
    - O comportamento dinâmico permite que:
        - parte da resposta seja processada na hora.
        - pedidos para o mesmo URL possam ter resposta diferente.
        - a execução de operações durante o tratamento de um pedido HTTP.
        - ter noção de histórico (guardar a morada para a próxima compra).

- Tarefas que requerem programação server-side:
    - Armazenamento persistente de dados recebidos via HTTP.
    - Procura de dados de uma BD no servidor utilizando critérios escolhidos no browser.
    - Oferecer navegação personalizada e conteúdos personalizados de acordo com o perfil de utilizador.
    - Controlo de acessos detalhado.
    - Guardar uma sessão de utilização da webapp.
    - Analítica de dados.

- Programação em cada lado: Cliente e Servidor
    - Componentes com âmbito e objetivos diferentes.
    - Em geral usam-se linguagens e ferramentas diferentes.
    - Têm ambientes de execução diferentes:
        - No cliente será um browser não determinado à partida, e que executa num sistema operativo do ambiente do utilizador, que não só é diferente do existente no servidor, como é não determinado à partida e distinto para vários utilizadores.
        - No servidor temos um ambiente controlado. SO e restante ambiente conhecidos.

- Programação server-side:
    - Pode fazer-se em várias linguagens de programação.
    - Recorre-se a web frameworks.
        - Web framework é um recurso de desenvolvimento de software que facilita a conceção, programação, manuntenção e operação de aplicações.
        - Inclui ferramentas e bibliotecas que facilitam:
            - acesso e processamento de parâmetros nos pedidos.
            - interação com bases de dados.
            - uso de sessões.
            - autenticação e autorização.
            - suporte para vários formatos de output (XML, JSON).
            - medidas de segurança contra ataques.

- Fatores a considerar na escolha de uma framework:
    - Esforço / curva de aprendizagem.
    - Produtividade:
        - Opinionated vs unopinionated: tem ou não recomendações sobre como resolver um problema em particular. Frameworks opinionated podem ser mais produtivos em tarefas comuns específicas, mas menos flexíveis noutras ocasiões.
        - Batteries included vs get it yourself: inclui bibliotecas que podem resolver todos os problemas com uma abordagem "por omissão", ou que requerem o desenvolvimento e/ou integração de bibliotecas externas.
        - Segue / sugere a adoção de boas práticas no desenvolvimento, como a arquitetura MVC.
        - Desempenho.
        - Suporte para cache.
        - Escalabilidade
            - Depois de esgotar as possibilidades de escala vertical, como pode ser configurada a escala horizontal (mais servidores).
        - Segurança
            - Vulnerabilidades.
            - Mecanismos de proteção.

- MVC
    - Model-View Controller, ou Arquitetura MVC é um padrão de desenvolvimento orientado para a reutilização de código e separação de três componentes relacionados:
        - Modelo
            - Gere o armazenamento dos dados e respetivo acesso.
            - Não é influenciado pela Vista e Controlador. Se alterado notifica os observadores sobre o evento de modificação.
        - Vista
            - View mostrada ao utilizador e interface com que interage.
        - Controlador
            - Componente de controlo que atualiza a Vista se o Modelo tem atualizações. Recebe notificações da Vista para pedidos de modificação no Modelo, decorrente de uma ação do utilizador.

- Aplicação convencional (WebApp Convencional)
    - Aplicação mais comum, onde a maior parte da lógica é tratada no servidor. Em alguns contextos é referida como Multiple Page Application, ou como Server Rendered Application.
    - A maioria das interações com o browser desencadeiam um pedido HTTP ao servidor, que devolve uma nova página.
    - Vantagens:
        - Facilidade de entendimento, conceção e desenvolvimento.
        - Maior facilidade de debugging.
        - Menor tempo de carregamento inicial.
        - Segurança.
        - Não exige suporte JS.
        - Não sobrecarregam o cliente.

- Single Page App (SPA)
    - Tipo de aplicação em que grande parte das interações ocorrem do lado do cliente. No início, o browser descarrega todo o código da aplicação (HTML, CSS, JS). A comunicação seguinte com o servidor é geralmente via API (ex: REST), essencialmente para obtenção de dados - não de HTML para uma página completa.
    - A tecnologia AJAX esteve na base desta filosofia, ao permitir atualizar parte de um documento web sem o recarregar por inteiro.
    - Vantagens:
        - Tempo de resposta reduzido depois do carregamento.
        - Interfaces com comportamento sofisticado.
    - Tecnologias:
        - React.
        - Angular.
        - JS simples.
    - SPA é mais recente mas não significa que seja melhor, depende da solução implementada.

- Progressive WebApp (PWA)
    - PWA são aplicações web modernas, que permitem uma experiência de utilização semelhante à conseguida com aplicações nativas.
        - Funcionamento rápido, fiável e cativante.
        - Permite push notifications.
        - Permite alguma funcionalidade offline.
        - Passíveis de instalação em dispositivos móveis e desktop.
    - Componentes:
        - ServiceWorker: controlo de tráfego de rede e cache.
        - App Manifest: ficheiro com metadados importantes.

- Tecnologia Java para WebApps
    - Uma aplicação Web Java consiste em:
        - Servlet que funciona como o controlador.
        - O modelo, com implementação de funcionalidades.
        - View (código Java ou JSP).
        - Configuração geral: web.xml

- Componentes web
    - Servlets - classes Java
        - para serviços e funções de controlo.
    - JSP
        - páginas que misturam conteúdo estático HTML com dinâmico (execução de código Java).

- Web container
    - Plataforma que aloja os componentes Web.
    - Reponsável pelos serviços:
        - Processamento dos pedidos.
        - Segurança.
        - Concorrência.
        - Gestão do ciclo de vida do componente web.
        - Gestão de nomes.
        - Transações

- Os componentes web têm de ser implantados (deployed) num web container para serem usados. A configuração geral pode arrumar-se num ficheiro XML, algumas configs podem ser feitas na fase de deployment.

- Aplicação Web em Java consiste em:
    - Componentes web.
    - Classes auxiliares, bibliotecas e recursos estáticos.
    - deployment descriptor.

- Ciclo de desenvolvimento:
    - Implementar os componentes web.
    - Especificar o deployment descriptor.
    - Compilar código fonte.
    - Opcionalmente, formar um pacote com todo o conteúdo da webapp.
    - Deployment num web container.
    - Aceder ao URL.

- Estrutura
    - Document root ou diretoria base
    - Contém:
        - JSPs
        - recursos cliente-site
        - recursos estáticos
        - configuração e bibliotecas server-side
    - WEB-INF/web.xml -> deployment descriptor.
    - Múltiplas formas de config:
        - no deployment descriptor
        - num ficheiro de propriedades
        - anotações nos vários ficheiros
    - Opções a configurar:
        - Mapeamento de endereços URL para componentes web
        - parâmetros de inicialização
        - permissões de acesso por perfil
        - definir os welcome files
        - ...
    - Configurações podem fazer-se para:
        - contexto (influencia toda a webapp)
        - servlet

- Web Archive (WAR)
    - ficheiro JAR com o conteúdo da pasta base da aplicação web.
    - facilita a arrumação e transporte da webapp.
    - packaging: processo de criação do ficheiro .war.

- Implantação pode fazer-se de dois modos:
    - instalação direta na diretoria base da webapp no repositório do web container.
    - instalação do ficheiro war no web container.

- JSF (java server faces)
    - Framework Java para desenvolvimento de aplicações web baseado em componentes de UI
    - Cada elemento de Ui tem um estado representado no servidor.
    - Facilita operações de validação e conversão de dados.
    - Facelet: objeto para descrever views.

- Java Beans
    - No contexto de padronizar e simplificar o desenvolvimento de aplicações
        - concentrar atenção na lógica de negócio.
    - beans são componentes de software, alojados num software container.

- Na prática uma aplicação web em java envolve:
    - componentes web, para os módulos Controlador, View de MVC.
    - Implementação das funcionalidades.
    - Configuração geral.

- Atributos servlet
    - Da aplicação
        - Têm a haver com a aplicação.
        - Guardados num objeto ServletContext.
        - Disponíveis para todas as servlets.
    - Da sessão
        - Podem ser consultados em múltiplos pedidos.
        - Guardados num objeto HttpSession.
        - Ativos enquanto a sessão estiver vazia.
    - Do pedido
        - Disponíveis apenas durante o atendimento do pedido.

- Java Server Pages (JSP)
    - Tecnologia que permite juntar conteúdo estático e dinâmico.
    - Facilita a construção de modelos ou templates.
    - Ficheiros .jsp.
    - Atendimento ao pedido.
    - Sintaxe
        - Conteúdo HTML no JSP
            - \<H1>Exemplo\</H1> => out.print("\<H1>Exemplo\</H1>")
        - Comentário HTML
            - <\!-- Comentário --> enviado para o cliente
        - Comentário JSP
            - <%-- ... --%> não são enviados para o cliente
        - Expressões
            - <%= expression %> avaliada e inserida no retorno da servlet: out.print(expression)
        - Scriptlets
            - <% code %> executada no atendimento do pedido
        - Declarações
            - <%! code %> inseridas no código fonte da servlet associado a este JSP. Úteis para definir variáveis.

- Threads em componentes web
    - a cada pedido o tomcat usa uma thread.
        - cada pedido tem um request e response único.
    - Elementos sujeitos a acesso concorrente:
        - Variáveis de instância da servlet.
        - Contexto da aplicação.
        - Atributos de sessão.

- Considerações sobre concorrência:
    - vulnerabilidades.
    - No desenho da aplicação, a programação deve acautelar potenciais situações de competição pelos dados em execução concorrente.
    - Zonas críticas devem ser protegidas para evitar problemas futuros.

- Frameworks vão ajudar:
    - Desenvolvimento
        - menos código
        - maior agilidade
    - Operação
        - funcionamento de operações comuns está implementado
        - atualizações ao framework protegem de vulnerabilidades conhecidas.
    - Soluções:
        - Spring web MVC
        - Vaadin

- Armazenamento de dados
    - três camadas:
        - Apresentação
        - Aplicação
        - Repositório de dados
    - Em MVC o modelo:
        - lida com os dados e gere as operações sobre os dados.
        - Pode ser mais ou menos complexo, no limite, um serviço que acede a outro serviço com uma arquitetura multi-camada e que termina numa forma de armazenamento persistente.
    - Programação para uso de um BD
        - Explícita: com a programação da ligação, e todas as leituras, escritas...
        - Implícita: via ferramentas que simplificam o desenvolvimento, escondendo o detalhe de operações comuns.

- JDBC
    - API para acesso a BD
        - Criar o esquema da BD via SQL
        - operações de escrita e de leitura de dados em tabelas, via SQL
    - É necessário adicionar o driver da BD à classpath (JAR)

- Object-Relational Mapping (ORM)
    - Visão dos dados na perspetiva ObjectOriented.
    - Há um mapeamento entre objetos e o esquema de uma BD relacional.
    - Os objetos podem ser lidos e escritos no reppsitório com a simples execução de um método.

- Java Persistent Architecture
    - Framework ORM para JAVA
        - casos mais simples e frequentes tratados com pouco código
        - menor necessidade de atualização de código.
        - menor dependência do SGBD.
    - Anotações no código do programa
        - referir entidades
        - referir propriedades
        - Caracterização da relação entre entidades.

- Spring Data JPA
    - O comportamento por omissão resolve muitas das necessidades frequentes.
    - Quando necessário é possível maior controlo, com configurações para
        - Consultas
            - Query Method: @Query("...")
            - JPA Named Queries: @NamedQuery(name="name", query="...")
        - Correspondência de campos e tabelas
            - @Table(name = "people")
            - @Column(name = "firt_name", nullable = "false")

- NoSQL
    - Termo associado a "not only SQL"
    - Repositórios com modelos de dados não relacionais
        - Visam eficácia, escalabilidade e ganhos de desempenho.
    - MongoDB, CouchDB, Redis, Neo4J, Cassandra, HBase