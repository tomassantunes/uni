# Resumo

- Sincronização de Relógios
	- A sincronização de relógios é o processo pelo qual os relógios de computadores ou nós de um sistema distribuído são ajustados para mostrar o mesmo tempo ou, pelo menos, tempos muito próximos.
	- Objetivo
		- Assegurar que todos os nós num sistema distribuído concordem sobre a ordem temporal dos eventos.
	- Métodos
		- Utiliza protocolos como o Network Time Protocol (NTP) para sincronizar relógios com uma referência de tempo global.
		- Algoritmos como o algoritmo de Berkeley ou o Algoritmo de Christian para sincronização interna entre nós.

- Exclusão Mútua Distribuída
	- Exclusão mútua distribuída refere-se à necessidade de garantir que, num sistema distribuído, apenas um nó, possa aceder a um recurso partilhado ou executar uma tarefa crítica de cada vez.
	- Objetivo
		- Prevenir conflitos e inconsistências resultantes do acesso simultâneo a recursos compartilhados.
	- Métodos
		- Algoritmos baseados em permissões, como o algoritmo de Ricart-Agrawala, onde os nós solicitam e recebem permissão de todos os outros nós antes de entrar na secção crítica.
		- Algoritmos baseados em token, onde um token único circula no sistema, e apenas o nó que detém o token pode entrar na secção crítica.
	- Importância
		- Fundamental para manter a integridade dos dados e a correta sequência de operações em ambientes onde múltiplos processos ou nós operam em paralelo.

- Replicação
	- num SD espera-se que os serviços tenham alta disponibilidade, o melhor desempenho possível e que o efeito das  falhas seja mínimo
	- Replicação
		- fundamental para SDs, na medida em que contribui para desempenho, alta disponibilidade e tolerância a falhas.
		- vantagens
			- ganho de desempeno
				- ...
			- aumento da disponibilidade
				- ...
			- tolerância a falhas
				- ...
		- requisitos
			- transparência
			- consistência
	- Replica Manager
		- Módulos ou servidores que contém as réplicas em cada computador
		- comunicam entre si, arquitetura cliente-servidor
		- cada RM tem uma réplica de tudo ou parte dos dados
		- Fases para atendimento do pedido de cliente
			- FrontEnd (módulo mais exterior do serviço) envia o pedido para um ou mais RM
				- FE comunica apenas com um RM, que depois se liga aos restantes
				- FE envia multicast a todos os RM
			- Coordenação
				- RMs coordenam-se para executarem a operação de forma consistente.
			- Execução
			- Acordo (agreement)
				- RMs entendem-se relativamente ao resultado e em função disso fazem rollback ou commit
			- Resposta
				- Um o mais RMs repondem ao FE

- Sharding
	- Sharding em bases de dados distribuídas é uma técnica de particionamento de dados onde uma base de dados é dividida em pedaços menores, conhecidos como "shards". Cada shard contém uma porção dos dados da base de dados total e pode ser armazenado num servidor físico ou lógico separado.
	- Objetivos
		- Melhorar a performance
			- Ao dividir a base de dados em shards menores, cada consulta só precisa de ser processada numa fração dos dados, reduzindo o tempo de resposta.
		- Escalabilidade horizontal
			- Facilita o dimensionamento do sistema de base de dados, permitindo adicionar mais servidores para acomodar mais shards, em vez de aumentar os recursos de um único servidor.
		- Balanceamento de carga
			- Distribui a carga de trabalho entre vários servidores, evitando sobrecarregar um único servidor.

- Sistema de Ficheiros Distribuído
	- permite às aplicações gravar e aceder a ficheiros remotos exatamente do mesmo modo que utilizam para os ficheiros locais
	- permite o acesso dos utilizadores aos seus ficheiros desde qualquer computador
	- Objetivos
		- emular a funcionalidade de um sistema de ficheiros (não distribuído) para aplicações cliente que podem estar em execução em vários computadores remotos.
	- Responsabilidades
		- organização
		- armazenamento
		- acesso
		- gestão de nomes
		- partilha
		- proteção/segurança dos ficheiros
	- Armazenamento centralizado
		- Risco de congestionamento
		- Risco de falhas
		- Tamanho de um ficheiro limitado à capacidade de um servidor
	- Armazenamento paralelo
		- Um ficheiro pode ser distribuído por várias máquinas
		- Metadados e dados podem ser alojados em servidores diferentes
	- Ficheiros
		- podem ser armazenados de forma persistente
		- contém dados e atributos (metadados)
		- manipulados através do serviço de ficheiros
			- criar, apagar, abrir, fechar, ler, escrever, append, seek, obter, atributos, definir um atributo, renomear
	- Diretorias
		- uma diretoria é um ficheiro que mapeia um nome (texto) em identificadores internos para os ficheiros
		- uma diretoria pode incluir o nome de outra diretoria, formando um esquema de nomes hierárquico
	- Requisitos de um SFD
		- Transparência
		- Controlo de concorrência
		- Replicação de ficheiros
		- Abertura e independência face a diferenças de hardware ou SOs
		- Tolerância a falhas
		- Consistência
		- Segurança
		- Eficiência
	- Serviço de ficheiros
		- Componentes
			- Serviço Flat File
				- operações sobre o conteúdo dos ficheiros
				- pedidos referem identificadores únicos (UFIDs)
				- ao criar um ficheiro é gerado um novo UFID
			- Serviço de diretorias
				- mapeia nomes de ficheiros em UFIDs
				- criar diretorias, adicionar ficheiros a diretorias
				- cliente do flat file
				- as diretorias têm referências para outras diretorias
			- Módulo cliente
				- executado em cada computador cliente
				- operações dos componentes anteriores e interface de programação aos programas (user-level)
				- guarda informação sobre a localização dos serviços anteriores.
		- Controlo de acessos
			- FS normal 
				- ao fazer open, com base no uid local
			- SFD
				- verificação efetua-se no servidor a cada pedido
	- NFS (Network File System)
		- Protocolo NFS
			- RPCs (remote procedure calls) que permitem aos clientes trabalhar com ficheiros remotos.
			- Independente do SO
		- Servidor NFS
			- ao nível do Kernel de um computador que age como servidor NFS
		- Os pedidos sobre ficheiros remotos são traduzidos pelo módulo cliente em operações do protocolo NFS e passados ao servidor que detém esses ficheiros.
		- Podem usar-se/exigir-se credenciais de identificação
		- controlo de acesso e autenticação
			- o servidor é stateless
			- servidor valida as permissões do utililizador a cada pedido
		- Mount Service: permite montar parte de um file system remoto por um cliente
		- Cache
			- no servidor
				- blocos de ficheiros e atributos (metadata) mantidos em memória
				- read ahead
				- persistência/consistência
					- write-through caching: atualizar memória e disco antes de responder ao cliente
					- delayed commit ou delayed write: escrever apenas na cache em memória, sincronização com o disco ocorre quando o ficheiro é fechado, ou sempre que pedido ou após um timeout (30s)
			- no cliente
				- cache sobre o resultado de read, write, getattr, lookup e readdir, de forma a reduzir os pedidos ao servidor e o tráfego na rede
				- o estado de um ficheiro ativo é atualizado com o servidor a cada 3s.
		- Desempenho
			- transparência de acesso e localização, tolerância a falhas
			- o servido é stateless, o que permite retornar o funcionamento após crash sem necessidade de procedimento especial de recuperação, o cliente perde a cache
			- normalmente não introduz penalizações relevantes comparativamente ao acesso a ficheiros locais
			- Problemas
				- escala limitada para a capacidade do servidor
				- sensível à latência da rede
				- desempenho relativamente inferior na operação write se usar write-through
	- VFS (Virtual File System)
		- Integração entre o sistema de ficheiro local remoto, encaminha cada pedido para o destino apropriado (NFS Client ou FS local)
		- Em NFS os ids dos ficheiros são os file handles
		- VFS contém um v-node por ficheiro aberto, permite saber se o mesmo é local ou remoto
		- Cliente NFS integrado no kernel
			- permite o acesso aos ficheiros através de system calls
				- Coopera com o VFS passando os dados remotos “tal como” o UNIX-FS faz para os dados/ficheiros locais
			- um único módulo cliente serve todos os processos user-level, com uma cache de blocos em uso.
			- a chave usada na encriptação do uid fica protegida a nível do kernel, a salvo das aplicações user-level
	- AFS (Andrew File System)
		- acesso transparente a ficheiros partilhados remotos para programas UNIX
		- o acesso aos ficheiros faz-se através das primitivas UNIX
		- Servidor AFS
			- armazena ficheiros UNIX, referenciados de modo semelhante ao NFS
		- Objetivo
			- Escalabilidade, alcançada via cache
				- Whole file serving: o servidor transmite o conteúdo inteiro de ficheiros e diretorias
				- Whole file caching: ao receber um ficheiro, o cliente faz uma cache persistente
		- Funcionamento:
			- quando uma aplicação do utilizador faz open de um ficheiro remoto que não tem uma réplica local, o servidor respetivo é localizado e envia uma cópia
			- a cópia é armazenda no file system do cliente e aberta, sendo devolvido ao utilizador o respetivo file descriptor unix
			- as operações de leitura e escrita ocorrem sobre essa réplica
			- ao efetuar um close se a réplica foi alterada, o conteúdo é enviado ao servidor AFS que atualiza a sua. A réplica permanece junto do cliente para eventual uso por outro utilizador da workstation.
		- Vice: corre no servidor
		- Venus: corre no cliente (módulo cliente no modelo abstrato)
		- Consistência
			- callback promise
				- garantia de Vice para Venus de que notificará a atualização do ficheiro sempre que outro cliente o alterar.
				- tem 2 estados
					- válida (usa a cópia em cache)
					- cancelada (necessita de obter uma cópia de Vice)
				- são revistas quando o servidor recebe uma operação close de um ficheiro atualizado.
		- outros aspetos
			- requer alterações no Kernel UNIX
				- manipular os ficheiros a partir de file handles e não com os usuais UNIX file descriptors.

# Frequências
### 1) Como funciona a replicação ativa. Até quantas falhas aguenta um sistema com 5 RMs.

R: Na replicação ativa os RM têm a mesma função que têm na replicação passiva que é executar a operação e enviar cópias dos dados atualizados aos RM Backup e estão organizados como um grupo. O Front End envia o pedido por multicast aos elementos do grupo e cada RM processa o pedido e responde ao FE, sendo que a falha de um RM não tem impacto sobre o serviço. Por fim, um sistema com 5 RMs tolera 2 falhas bizantinas e tolera 4 falhas do tipo crash.

### 2) O que é a arquitetura Gossip?

R: A arquitetura Gossip, é uma framework que permite que os RMs possam ficar temporariamente desligados, sofrendo updates individualemente e quando voltarem a ligar-se trocam mensagens com as atualizações, as quais são chamadas de **_gossip_** messages. Esta arquitetura oferece dois tipos de operações, a operação query, esta é uma operação apenas de leitura, e a operação update que modifica os dados mas não os lê.

### 3) O que entende por Shard? Vantagens e desvantagens de Sharding.

R: Sharding, no contexto das BDs distribuídas, consiste na distribuição dos dados por várias BDs, os dados são particionados e cada bloco vai para uma BD/servidor dedicado, é a chamada partição horizontal, permite distribuir dados e carga sobre os servidores. Algumas das vantagens de sharding são: a melhoria na performance visto que, as operações de leitura e escrita são distribuídas por vários servidores, reduzindo a carga em cada servidor, outra vantagem, como mencionado anteriormente, é a escalabilidade horizontal, permitindo adicionar servidores ao invés de aumentar a capacidade um único servidor, e temos também ao utilizar sharding, uma maior autonomia e menos falhas em cascata visto que, cada shard pode operar de forma independente. Algumas das suas desvantagens são: a complexidade de design e manuntenção, problemas de consistência de dados e custos iniciais mais altos.

### 4) Qual a função da VFS (Virtual File System)?

R: A função do sistema virtual de ficheiros é fazer a integração entre o sistema de ficheiros local e o remoto, encaminhando cada pedido para o destino apropriado (NFS Client ou SF local). Em NFS os identificadores dos ficheiros são file handles, contém a informação que o servidor precisa para distinguir os ficheiros, o VFS contém um v-node por ficheiro aberto que permite saber se o mesmo é local ou remoto. O cliente NFS é integrado no Kernel, ou seja, não tem de ser carregado como biblioteca. Assim, é possível realizar o acesso aos ficheiros através de system calls cooperando com o VFS, passando os dados remotos "tal como" os UNIX-FS faz par o dados/ficheiros locais. Um único módulo cliente serve todos os processos user-level, com uma cache dos blocos em uso. A chave usada na encriptação do uid fica protegida a nível do kernel, a salvo das aplicações user-level.


### 5) Qual é a diferença entre NFS e AFS?

R: No protocolo NFS o utilizador realiza as operações sobre os ficheiros diretamente sobre o servidor (este guarda as alterações na cache e só atualiza o disco quando este for fechado em caso de delayed commit ou atualiza o disco em caso de write-through). Em caso de crash do sistema, devido ao facto do servidor ser stateless só se perderia a cache do cliente. Este protocolo tem escala limitada pela capacidade do servidor, é sensível à latência da rede e o desempenho é relativamente inferior na operação write se usar write-through no servidor. Já no protocolo AFS, o servidor envia uma réplica do ficheiro ao cliente, esta réplica é armazenada no file system do cliente e aberta, sendo devolvido ao utilizador o respetivo file descriptor. As operações de leitura e escrita que o cliente executa ocorrem sobre essa réplica. Ao efetuar um close, se a réplica foi alterada, o conteúdo é enviado ao servidor AFS que atualiza a sua. A réplica permanece junto do cliente para eventual uso por outro utilizador da workstation. Este protocolo tem como principal objetivo a escalabilidade, existindo assim um bom desempenho para um elevado número de utilizadores e reduzindo a carga no servidor.

### 6) Distinga os modos de sincronização interna e externa de relógios num sistema.

R: Os relógios de sincronização interna não estão necessariamente sincronizados de modo externo, ou seja, se cada nó de um sistema está sincronizado de modo externo (com a mesma fonte) com limite D, então esse sistema está internamente sincronizado com um limite 2D. A sincronização interna, envolve a coordenação dos relógios dos próprios computadores num sistema, sem qualquer referência a um padrão de tempo externo. Já na sincronização externa, os relógios do sistema são alinhados com uma fonte de tempo externa, como por exemplo, o tempo universal coordenado (UTC).

### 7) Descreva sucintamente o algoritmo de Cristian.

R: O algoritmo de Cristian é um algoritmo probabilístico, em que se sincroniza se o tempo para a troca de mensagens cliente-servidor é suficientemente pequeno quando comparado com a precisão desejada. O algoritmo tem o seguinte funcionamente: o cliente envia um pedido para recolher o tempo de relógio ao servidor e regista o tempo local no momento do envio deste pedido ($T_1$). Quando o servido recebe o pedido, regista o tempo atual do seu relógio ($T_2$) e envia essa informação de volta ao cliente. Ao receber a resposta, o cliente regista o tempo local novamente ($T_3$), de seguida, o cliente calcula o tempo de viagem da mensagem (Round-Trip Time - RTT) como sendo a diferença entre $T_3$ e $T_1$, o atraso de rede é assumido como sendo metade do RTT, sob a hipótese de que o tempo de ida e volta é simétrico, então, assumindo este atraso, o cliente ajusta o seu relógio para o tempo do servidor $T_2$ mais o atraso de rede estimado: $T_2 + (T_3 - T_1)/2$.

### 8) Descreva sucintamente o algoritmo de Berkeley.

R: O algoritmo de Berkeley é um algoritmo para sincronização interna de um grupo de computadores, em que uma máquina é escolhida para coordenar, esta será chamada de master. O master interage periodicamente com todos os elementos do grupo (slaves e ele próprio), para saber a diferença relativamente a cada um, de seguida estima a hora em cada slave, pela observação do tempo de viagem das mensagens e pelo valor recebido (como em Cristian), faz a média de todos os valores (incluindo o seu tempo), mas em vez de enviar o tempo atualizado aos slaves (o que estaria sujeito ao tempo de envio variável), o master envia a cada um o valor exato que este deve usar para ajustar o seu relógio, se este master falhar, outra máquina será escolhida para assumir a função.

### 9) O protocolo NTP permite três modos para sincronização de relógios em servidores.
#### a) Descreva esses métodos de sincronização.

R: O primeiro método de sincronização que o protocolo NTP oferece, é o método multicast que é utilizado em redes locais de alta velocidade, onde um ou mais servidores enviam periodicamente o tempo num broadcast. Os servidores noutras máquinas da rede acertam o seu relógio assumindo um pequeno delay, este método oferece assim, baixa precisão.
O próximo método, é o procedure-call em que um servidor aceita pedidos de outros computadores, aos quais responde com a informação horária que tem (Como Cristian). Este é utilizado quando se pretende maior precisão que a oferecida no modo multicast, ou simplesmente este não é possível.
Por último, temos o modo simétrico para a sincronização entre servidores que fornecem a informação em redes locais e em níveis mais altos da NTP subnet, onde se pretende a máxima precisão. Um par de servidores trabalha de modo simétrico, troca mensagens com informação horária, sendo que o tempo das mensagens também é considerado.

#### b) Qual o método em que se consegue a precisão máxima.

R: O método em que se consegue a precisão máxima é no modo simétrico.

### 10) No contexto de Sistema de Ficheiros Distribuído NFS, qual é o papel do sistema de ficheiros virtual (virtual file system) relativamente às aplicações de utilizador?

R: No contexto de Sistemas Distribuídos NFS, o papel do sistema de ficheiros virtual relativamente às aplicações de utilizador é fazer a integração entre o sistema de ficheiros local e o remoto, encaminhando cada pedido para o destino apropriado.

### 11) No Sistema de Ficheiros Distribuído NFS o servidor é stateless. Indique as suas vantagens e desvantagens.

R: No sistema de ficheiros Distribuído NFS podemos observar algumas vantagens, como por exemplo a transparência de acesso e localização, tolerância a falhas. Como o servidor é stateless, este permite retornar o funcionamento após crash sem necessidade de procedimento especial de recuperação, perdendo-se apenas a cache do cliente, e por fim, este normalmente, não introduz penalizações muito relevantes comparativamente ao acesso a ficheiros locais. Mas, também tem as suas desvantagens, como a escala limitada pela capacidade do servidor, ser sensível à latência da rede e o seu desempenho é relativamente inferior na operação write se usar write-through no servidor.

### 12) Uma empresa decidiu replicar o servidor de backend do seu serviço, que se encontrava numa única máquina com probabilidade 0,06 de falhar ou ficar incontactável, para uma segunda máquina idêntica. Apresente uma estimativa para a taxa de disponibilidade do serviço com as duas máquinas no backend.

R: $p = 0,06$; $N = 2$ máquinas
$1 - p^N = 1 - (0,06)^2 = 0,9964$

### 13) Indique o que é consistência linear.

R: Diz-se que um objeto é linearmente consistente se, para qualquer execução, existe algum encadeamento/sequência das operações desencadeadas por todos os clientes em que, a sequência permita alcançar uma única cópia correta dos objetos e a ordem das operações na sequência esteja de acordo com o tempo real a que efetivamente ocorreram.

### 14) Indique o que é consistencia sequencial.

R: Diz-se que um objeto replicado obedece à consistência sequencial se, para cada execução, existe uma sequência de operações desencadeadas por todos os clientes, em que a sequência permita alcançar uma única cópia correta dos objetos e em que a ordem das operações na sequênciaestá de acordo com a ordem no código do programa do cliente que as executa/solicita. A consistência sequencial não depende da precisão dos relógios para a verificação dos timestamps de cada operação em máquina diferentes, esta não usa referências temporais, mas antes uma ordem (sequência).

### 15) Uma empresa pretende ter um sistema replicado e com tolerância a falhas, apto para continuar a prestar um serviço correto mesmo na presença de 4 falhas bizantinas. Qual é o modelo de replicação que deve ser escolhido e quantos RM devem existir no backend do serviço?

R: De forma a tolerar falhas bizantinas, a empresa terá de escolher o modelo de replicação ativa, visto que o modelo de replicação passiva não tolera falhas bizantinas.

$N = 4$ falhas bizantinas
$RMs = 2N + 1 = 2 * 4 + 1 = 9 RMs$

Devem existir 9 RMs no backend do serviço para que as condições da empresa sejam alcançadas.

### 16) Com o tipo de replicação passiva, que tipo de falhas pode o sistema tolerar e quantas podem ocorrer sem que o serviço esteja fechado?

R: O modelo de replicação passiva apenas tolera crashes de servidores. Este modelo tolera N crashes de servidores com $N + 1$ RMs.

### 17) Qual é o funcionamento do AFS quando uma aplicação do utilizazdor pretende aceder a um ficheiro remoto?

R: Quando uma aplicação do utilizador faz open de um ficheiro remoto que não tem uma réplica local, o servidor respetivo é localizado e envia uma cópia, esta cópia é armazenada no file system do cliente e aberta, sendo devolvido ao utilizador o respetivo file descriptor unix. As operações de leitura e escrita irão ocorrer sobre essa réplica. Ao efetuar um close, se a réplica foi alterada, o conteúdo é enviado ao servidor AFS que atualiza a sua. A réplica permanece junto do cliente para eventual uso por outro utilizador.

### 18) Funcionalidade que existem nos serviços de directoria que não existam nos serviços de Nomes?

R: Algumas funcionalidades que existem nos serviços de diretoria e não nos serviços de nomes são: armazenamento de metadados, pesquisa e filtros complexos, gestão de identidade e acesso, estrutura hierárquica e organizacional, replicação e distruição de dados, integração com sistemas de segurança e suporte a protocolos de diretoria.

### 19) Componentes genéricos da arquitectura de um serviço de ficheiros, e suas respectivas funções.

R: Os componentes genéricos da arquitetura de um serviço de ficheiros são o serviço flat file, o serviço de diretorias e o módulo cliente. O serviço flat file executa operações sobre o conteúdo dos ficheiros, os pedidos referem ficheiros com identificadores únicos no SD (UFIDs) e ao criar um ficheiro, é gerado um novo UFID. O serviço de diretorias mapeia nomes (texto) de ficheiros em UFIDs, cria diretorias, adiciona ficheiros a diretorias, é cliente do serviço flat file e num esquema hierárquico as diretorias têm referências para outras diretorias. Por fim, o módulo cliente é executado em cada computador cliente, integra e estende as operações dos componentes anteriores, disponibiliza uma interface de programação aos programas e guarda informação sobre a localização na rede dos serviços de diretorias e flat file.

### 20) Motivo de usar replicação num sistema distribuído SD?

R: Num sistema distribuído espera-se que os serviços tenham alta disponibilidade, o melhor desempenho possivel e que o efeito das falhas seja mínimo, a replicação contribui para estas necessidades, providenciando desempenho, alta disponibilidade e tolerância a falhas.

# Testes ChatGPT
## Teste 1
### 1) Explique a importância da noção de tempo em sistemas distribuídos.

R: Nos sistemas distribuídos é importante ter uma noção de pois interessa saber a hora certos eventos ocorreram, em diferentes máquinas, para saber se um evento E1 é anterior ou posterior a um evento E2, reconstituir uma sequência ordenada, saber se dois eventos ocorreram ao mesmo tempo e no caso de querermos executar um evento a uma hora específica.

### 2) Descreva o conceito de skew e clock drift e a sua relevância em sistemas distribuídos.

R: Skew é a diferença instantânea na leitura de dois relógios, clock drift é o desvio resultante da contagem do tempo usando frequências (1/período) diferentes. Estes são essenciais em sistemas distribuídos devido à necessidade de coordenação e sincronização precisa entre diferentes componentes do sistema.

### 3) Compare o algoritmo de Cristian e o Algoritmo de Berkeley para sincronização de relógios.

R: O algoritmo de Cristian é um algoritmo probabilístico em que sincroniza os relógios com uma fonte externa, se o tempo para a troca de mensagens cliente-servidor é suficientemente pequeno quando comparado com a precisão desejada, o processo p envia pedido $m_r$ e recebe um tempo t em $m_t$, p regista o tempo de viagem de $m_r$ e $m_t$: $T = Tm_r + Tm_t$. Já o algoritmo de Berkeley é um algoritmo de sincronização interna de um grupo de computadores, em que uma máquina é escolhida para coordenar o grupo, a chamada master, e periodicamente a máquina master vai interagir com os elementos do grupo para saber a diferença relativamente a cada um, estima a hora em cada slave (elemento do grupo), e faz a média de todos os valores. Mas, em vez de enviar o tempo atualizado aos slaves, o que estaria sujeito ao tempo de envio variável, o master envia a cada slave o valor exato que este deve usar para ajustar o seu relógio.

### 4) Discuta as vantagens da replicação em sistemas distribuídos.

R: As vantagens da replicação em sistemas distribuídos são: o ganho de desempenho, pois a cache vai estar mais próxima do cliente, o que permite melhores tempos de acesso e diminui a latência, as coleções de dados são dividas, reduzindo assim o tempo de procura e a replicação de servidores permite melhores tempo de resposta e evita a sobrecarga em servidores; aumento da disponibilidade, visto que com a replicação dos dados, em caso de falha de um servidor a aplicação cliente pode ainda ser atendida por um servidor alternativo, logo o serviço contínua disponível; e por fim, a tolerância a falhas que a replicação apresenta, devido à possibilidade de ter vários servidores replicados, capazes de executar a mesma tarefa.

### 5) Explique o conceito de sharding e como este contribui para a eficiência dos sistemas distribuídos.

R: Sharding no contexto das Bases de Dados distribuídas em sistemas distribuídos, consiste na distribuição dos dados por várias bases de dados. O sharding contribui para a eficiência uma vez que os dados vão ser divididos entre vários servidores, diminuindo assim a carga em cada servidor individual, e melhorando a performance.

### 6) Descreva as principais características e requisitos de um sistema de ficheiros distribuído.

R: Os sistemas de ficheiros distribuídos permitem às aplicações gravar e aceder a ficheiros remotos exatamente do mesmo modo que utilizam para os ficheiro locais e permite o acesso dos utilizadores aos seus ficheiros desde qualquer computador. Este tem como objetivo emular a funcionalidade de um sistema de ficheiros para aplicações cliente que podem estar em execução em vários computadores remotos. Os SFDs são responsáveis pela organização, armazenamento, acesso, gestão de nomes, partilha e proteção/segurança dos ficheiros. Os seus requisitos são a transparência, o controlo de concorrência, a replicação de ficheiros, a abertura e independência face a diferenças de hardware ou SOs, a tolerância a falhas, consistência, a segurança e por fim a eficiência.

### 7) Dê exemplos de sistemas de ficheiros distribuídos e discuta as suas diferenças.

R: Dois exemplo de sistemas de ficheiros distribuídos são o Sun Network File System, desenvolvido em 1985, e o Andrew File System, desenvolvido no final dos anos 80. Uma diferença entre estes dos sistemas de ficheiros distribuídos é o modelo de caching, o NFS usa um modelo de cache não persistente, o que significa que os dados não são armazenados localmente após o reinício. AFS, por outro lado, utiliza um sistema de cache persistente, mantendo uma cópia local dos dados para melhorar a eficiência e reduzir o tráfego de rede. Outra diferença é a escalabilidade e consistência, o AFS é projetado para ser mais escalável e oferece melhor consistência de dados em ambientes de grande escala em comparação com o NFS. Por último, temos a segurança, o AFS implementa um modelo de segurança mais robusto, com autenticação e controlo de acesso mais rigorosos, enquanto o NFS tem um sistema de segurança mais básico.

## Teste 2
### 1) Explique a diferença entre o modelo download/upload e o acesso remoto em sistemas de ficheiros.

R: A diferença entre o modelo download/upload e o acesso remoto a ficheiros é que, no modelo download/upload, o cliente sempre que quiser fazer alterações a um ficheiro, tem que o ir buscar ao servidor, e depois de fazer as suas alterações tem que o enviar novamente ao servidor. No modelo de acesso remoto, o cliente pode fazer as alterações e executar métodos sobre os ficheiros diretamente no servidor.

### 2) Descreva as vantagens e desafios associados ao caching em sistemas de ficheiros distribuídos.

R: Algumas vantagens associadas ao caching em sistemas de ficheiros distribuídos são a melhoria do desempenho, visto que reduz o número de acessos necessários ao servidor armazenando cópias locais de dados frequentemente utilizados, redução de carga na rede devido à frequência de acessos ao servidor reduzir e o aumento da disponibilidade dos dados, pois estes estarão armazenados localmente em cache, mesmo com a conexão em baixo. Mas, o caching também tem desafios, como: a consistência dos dados, pois manter a consistência dos dados, entre os que estão armazenados localmente e os que estão no servidor pode ser complicado, a gestão da cache pois decidir que dados devemos armazenar em cache exige algortimos eficientes e por fim, o custo de armazenamento, pois a cache irá necessitar de armazenamento adicional, o que pode aumentar os custos, especialmente em sistemas de grande escala.

### 3) Discuta os problemas do MapReduce que o Apache Spark procura resolver.

R: Os problemas que do MapReduce que o Apache Spark procura resolver são: a falta de eficiência quando são necessárias múltiplas passagens, o facto de que os problemas têm de ser convertidos numa série de operações Map e Reduce, o facto de que a próxima fase nunca poderá começar até que a anterior acabe, o output tem de ser guardado no sistema de ficheiros antes do próximo passo começar e por fim, o facto de que o armazenamento envolve escrita no disco e replicação.

### 4) Explique o conceito de RDDs no Spark e a sua importância.

R: Os RDDs (Resilient Distributed Datasets) são tabelas que conseguem ser divididas (sharded) por vários servidores, que conseguem armazenar qualquer tipo de dados e são imutáveis, ou seja, podemos processar uma RDD para criar uma nova, mas não podemos alterar o seu conteúdo original. Os RDDs apresentam dois tipos de operações, as transformações que recebem como input um RDD e criam um novo, e as ações, que avaliam um RDD e criam um valor. Este conceito é importante porque vem resolver os problemas do Map & Reduce.

### 5) Explique como as CDNs ajudam a resolver problemas de escalabilidade e desempenho na Internet.

R: As CDNs ajudam a resolver problemas de escalabilidade e desempenho na Internet de várias maneiras, como a distribuição geográfica de conteúdo pois, armazena conteúdo em múltiplos servidores ao redor do mundo, reduzindo a distância física entre o utilizador e o servidor, melhorando assim os tempos de carregamento, a distribuição de carga, de forma a reduzir a carga nos servidores, as CDNs distribuem os pedidos pelos vários servidores e por fim o cashing eficiente, as CDNs utilizam técnicas avançadas de cashing para armazenar versões de conteúdo que são frequentemente acedidos, o que reduz a necessidade de comunicar com o servidor.

### 6) Descreva as estratégias utilizadas pelas CDNs para otimizar a entrega de conteúdo.

R: Algumas estratégias utilizadas pelas CDNs para otimizar a entrega de conteúdo são: o caching de conteúdo, armazena cópias de conteúdos populares em vários locais para reduzir a latência e melhorar o tempo de resposta, a distribuição geográfica, ao localizar servidores em diferentes regiões minimiza-se a distância até aos utilizadores finais e por fim, a otimização de rota de rede, utilizando algoritmos avançados para determinar a rota mais rápida e eficiente para entregar o conteúdo.