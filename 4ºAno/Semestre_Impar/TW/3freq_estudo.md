# Perguntas
1. Como é que os cookies contribuem para a manutenção da sessão em aplicações web?

R: Os cookies contribuem para a manuntenção da sessão ao guardarem dados de pedidos HTTP que podem ser necessários enviar para pedidos posteriores. Eles guardam informações como identificadores de sessão, permitindo que o servidor reconheça pedidos em sequência do utilizador.

2. De que forma a sessão é diferente da autenticação nas aplicações web?

R: A sessão e a autenticação em aplicações web são diferentes pelo seu propósito. A sessão refere-se ao período de interação do utilizador com a aplicação, controlada por um identificador de sessão. Já a autenticação é o processo de verificar a identidade de um participante num processo.


3. Quais são os métodos principais do objeto HttpSession em Java e quais as suas funções?

R: Os métodos principais do objeto HttpSession são: getId(), que devolve o id da sessão atual, getAttribute(String name), que devolve o objeto guardado no atributo com o nome `name`, e por fim, o setAttribute(String name, Object value), que vai inserir o objeto `value` no atributo `name`.

4. Como é que a implementação do SSO impacta a gestão de identidades em ambientes corporativos?

R: A implementação do SSO (Single Sign-On) impacta na gestão de identidades em ambientes corporativos, pois simplfica o acesso, visto que os utilizadores podem aceder a vários sistemas e aplicações com as mesmas credenciais. [Resposta GPT](https://chat.openai.com/share/d4adbefa-f497-4b0e-9e87-9cb1a7bb6ac9)

5. Explique a diferença entre autenticação e autorização. Como estes conceitos se aplicam num cenário de aplicação web empresarial onde diferentes níveis de acesso são necessários?

R: Autenticação é a garantia sobre a identidade do participante num processo, enquanto que a autorização é uma garantia de que o acessoa a uma operação sobre um recurso por parte de um utilizador está de acordo com a política de segurança. Em aplicações web empresariais, a autenticação garante que apenas utilizadores identificados podem aceder ao sistema, enquanto que a autorização determina o nível de acesso e operações que cada utilizador pode realizar.

6. Como é que a delegação de autenticação e autorização para o servidor ou container pode beneficiar o desenvolvimento de uma aplicação web? Quais são os potenciais riscos associados a esta abordagem?

R: A delegação de autenticação e autorização para o servidor ou container beneficia o desenvolvimento de uma aplicação web, pois permite o programador focar-se no desenvolvimento da funcionalidade, não tendo que escrever código para autenticar utilizadores. No entanto isso pode trazer riscos se o servidor ou container não estiver configurado corretamente, levando a potenciais vulnerabilidades de segurança.

7. Discuta como o Single Sign-On (SSO) e Single Log-Out (SLO) melhoram a experiência do utilizador em sistemas corporativos. Quais são os desafios técnicos e de segurança associados à implementação do SSO?

R: O Single Sign-On melhora a experiência do utilizador em sistemas corporativos permitindo que cada utilizador tenho apenas uma credencial que pode utilizar para todos os sistemas e aplicações. O Single Log-Out melhora a experiência do utilzador ao terminar sessão em todos os sistemas e aplicações associados ao mesmo tempo, fazendo com que o utilizador não tenha de fazer log-out em cada um desses. Alguns desafios são a gestão de tokens de autenticação e a integração com diferentes sistemas e protocolos de segurança.

8. Como é que os JWTs são utilizados para garantir a segurança e a integridade dos dados em comunicações web? Discuta um cenário onde o uso de JWT seria ideal.

R: Os JWTs são utilizados para garantir a segurança e a integredidade dos dados em comunicações web, guardando os dados que vão ser transportados encriptados, através de criptografia assimétrica. Um cenário onde o uso de JWT seria ideal, seria por exemplo no login de um sistema que utilize o SSO, utilizando JWTs para transportar os dados do login para o servidor.

9. Qual é a importância do MFA e do 2FA na segurança de sistemas web? Forneça um exemplo de como o 2FA pode ser implementado em uma aplicação web.

R: A importância do MFA e do 2FA na segurança de sistemas web é a redução do risco de usurpação de identidade, acessos não autorizados e perda ou sequestro de dados ao tornar o processo de autenticação mais sólido através da adição de passos intermédios, por exemplo, username + passoword + código de autenticação recebido por SMS.

10. Por que é que é crucial usar SSL em aplicações web, especialmente quando se trata de dados sensíveis? Explique o processo de handshake SSL e como ele contribui para a segurança.

R: O uso de SSL é crucial para proteger a comunicação entre o browser do utilizador e o servidor, especialmente para dados sensíveis. O handshake SSL estabelece uma conexão segura, trocando chaves de criptografia e verificando a identidade do servidor através de certificados digitais.

11. Descreva os passos necessários para configurar SSL numa aplicação Spring. Como é que a configuração difere dependendo se a aplicação é autónoma ou não?

R: Para configurar SSL numa aplicação Spring, é necessário primeiro gerar um certificado SSL e depois configurar o servidor para utilizar HTTPs. Em aplicações autónomas a configuração pode ser feita adicionando propriedades especíoficas no ficheiro de configuração, enquanto que em aplicações não autónomas, pode ser necessário configurar o SSL no servidor.

12. Quais são as principais diferenças entre testes unitários, de integração, sistémicos e de aceitação em aplicações web?

R: Os testes unitários são geralmente testes sobre uma função ou método. Os testes de integração validão as interfaces entre módulos ou componentes de um sistemas. Os testes sistémicos testam os sistema como um todo, realizando operações que se esperam de forma a testar cada funcionalidade. Por fim, os testes de aceitação verificam se o software está ou não pronto e em conformidade com o interesse do utilizador ou cliente, com a legislação, com o contratualizado e com os critérios para uma versão de produção ou uma versão alpha.

13. Como é que a automatização dos testes contribui para a eficiência do processo de teste em aplicações web?

R: A automatização dos testes contribui para a eficiência do processo de teste em aplicações web, dispensando tarefas manuais de um operador humano, facilitando a repetição e agendamento e tornando mais simples a execução distribuída, fazendo com que se possam fazer testes mais realistas e aferir diferenças de desempenho em função da origem dos pedidos.

14. Por que é que os testes de usabilidade são importantes no desenvolvimento de aplicações web e que aspectos geralmente avaliam?

R: Os testes de usabilidade são importantes no desenvolvimento de aplicações web pois verificam se o utilizador consegue utilizar a aplicação com sucesso sem esforço desnecessário. Os aspetos que geralmente avaliam são: a facilidade de navegação, a clareza das instruções, a rapidez de realização de tarefas e a satisfação geral do usuário com a aplicação.

# Notas
## Sessão HTTP

- protocolo stateless
- Cookie
	- pequeno elemento com dados que o servidor pede ao browser para guardar, com o objetivo de enviar pedidos posteriores
	- no servidor, podem ser vistos programaticamente com getCookies() sobre o objeto que representa o pedido HTTP.
- Sessão e autenticação são conceitos diferentes.

- Sessão
	- período de atividade do utilizador no site
		- esse período tem diversas interações browser-servidor (pares de pedido-resposta HTTP)
		- coexiste em paralelo com outras sessões
	- abrange o conjunto de todas as interações com a aplicação web, desde o momento em que acede à primeira página até que:
		- fecha o browser
		- termina explicitamente a sessão
			- por uma ação do utilizador ou do código da aplicação
		- a sessão expira por inatividade
			- intervalo de tempo definido numa configuração server-side
	- Identificador
		- gerado pelo servidor e enviado para o cliente, para este guardar num cookie
		- browser envia o Session ID a cada interação para distinguir os pedidos HTTP associados a diferentes sessões
			- se o browser não suportar cookies, alguns servidores usam
				- URL Rewriting: adicionar dados aos endereços, que serão descodificados no servidor para obter a session id
		- a nível de programação, acesso à sessão permite:
			- manter a interação e navegação coerentes
			- associar dados a cada utilizador/sessão
			- gerir um ciclo de acesso à aplicação web, ou a parte dela, exigindo uma sessão válida.
	- no cliente:
		- num browser normal, espera-se o uso de cookies
		- se limpar os cookies, perde a sessão
		- em dois browsers diferentes na mesma máquina, o normal é ter sessões separadas
			- ainda que a mais baixo nível e em determinado ambiente e configuração, haja exceções
		- para um só browser
			- acessos ao site em diferentes separadores da mesma janela costumam partilhar a mesma sessão
			- acessos ao mesmo site desde janelas diferentes (do mesmo browser) - o comportamento pode depender do browser ou configuração.
	- armazenamento
		- memória do servidor
		- persistência em ficheiro ou BD
			- importante para a recuperação de falha de um nó de um cluster de modo transparente para o cliente e para partilha entre servidores replicados
		- alternativa: ter dados no lado cliente, em cookies
			- facilitaria redundância de servidores (stateless)
			- implica envio sistemático dos cookies para o servidor
			- apenas se não guarda elementos críticos, por motivos de segurança
	- no servidor:
		- objeto HttpSession
			- permite identificar o utilizador e associar-lhe dados, ao longo das diferentes interações que faz com a aplicação
			- métodos importantes:
				- Object getAttribute(String name)
				- void setAttribute(String name, Object value)
				- void invalidate()
		- objeto sessão obtido a partir do pedido HttpServletRequest
			- HttpSession getSession(boolean create)
				- Devolve a sessão atual, ou cria uma nova, se desejado e necessário
	- possíveis usos:
		- implementar funcionalidades do tipo "carrinho de compras"
		- saber as escolhas do utilizador sem exigir a submissão de todos os dados em cada interação browser-servidor
		- manter um contexto sem leituras de BD

## Autenticação, autorização, SSO, MFA
- Autenticação
	- garantia sobre a identidade do participante num processo

- Autorização
	- garantia de que o acesso a uma operação sobre um recurso por parte de um interveniente está de acordo com a política de segurança

- OAuth 2.0
	- cliente pede autorização ao resource owner. Este pedido pode ser feito diretamente ao resorce owner, ou, preferivelmente, indiretamente através do servidor de autorização como intermediário.
	- o cliente recebe uma garantia de autorização, que é uma credencial representativa da autorização do resource owner, utilizando 1 de 4 tipos de garantia diferentes. O tipo de garantia depende do método pelo qual o cliente pediu a autorização e os tipos que o servidor de autorização suporta.
	- o cliente pede um access token ao autenticar-se no servidor de autenticação com a garantia de autorização do resource owner.
	- o servidor autentica a garantia, e se for válida devolve um access token.
	- o cliente pede um protected resource ao servidor de recursos, autenticando o cliente através do access token.
	- se o access token for válido, envia o recurso ao cliente.