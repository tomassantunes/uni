# Resumo
## Cloud Computing

Autoatendimento na hora e em função da necessidade
- A consumer can literally provision computing capabilities, such as server time and network storage, as needed automatically without requiring human interaction with each service provider.

Acesso com grande largura de banda
- Capabilities are available over the network and accessed through standard mechanisms that promote use by heterogeneous thin or thick client platforms (mobile phones, tables, laptops and workstations).

Resource pooling (carregamento antecipado de uma bateria de recursos)
- The provider's computing resources are pooled to serve multiple consumers using a multi-tenant model, with different physical and virtual resources dynamically assigned and reassigned according to consumer demand.

Elasticidade
- Capabilities can be elastically provisioned and released, in some cases automatically, to scale rapidly outward and inward commensurate with demand. To the consumer, the capabilities available for provisioning often appear to be unlimited and can be appropriated in any quantity at any time.

Mensurabilidade do serviço
- Cloud systems automatically control and optimize resource use by leveraging a metering capability at some level of abstraction appropriate to the type of service (storage, processing, bandwith, and active user accounts). 
- Resource usage can be monitored, controlled, and reported, providing transparency for both the provider and consumer of the utilized service.


### More cloud computing
- Assente em tecnologias da internet para oferta de serviços escaláveis e elásticos.
- O termo **"elastic computing"** tem a ver com a capacidade de ativar dinamicamente o acesso a recursos computacionais, de modo a responder a uma carga variável.
- Segurança e manuntenção ficam a cargo dos fornecedores (CSP, Cloud Service Provider).
- A especialização e concentração favorecem a eficiência nos CSPs.
- Eficiência e redução de custos para CSPs reflete-se também para os utilizadores, que poderão ter menores encargos com cloud.
- Armazenamento de dados:
	- Perto do site que precisa deles
	- Junto à ligação de rede de alta velocidade
	- Facilita acessos com origem em diversas localizações
- Estratégia de armazenamento aumenta a fiabilidade e segurança, e pode contrinuir para reduzir custos associados à comunicação.

#### Tipos de Cloud
- Pública
	- infraestrutura disponibilizada ao grande público e é operada por um consórcio.
- Privada
	- Infraestrutura é operada por uma só organização.
- Comunitária
	- Infraestrutura é partilhada por diversas entidades e está ao serviço de uma comunidade que usualmente tem alguns interesses em comum.
- Híbrida
	- Combinação de um ou mais clouds (pública, privada ou comunitária) heterogéneas através de normas (standards) que permitem portabilidade de dados e aplicações.

#### Benefícios
- Recursos, como CPU, armazenamento, rede e largura de banda são **partilhados**.
- Ao executar várias aplicações num sistema, em geral espera-se que o pico de solicitações de cada uma não ocorra ao mesmo tempo, e desse modo o uso global dos recursos é otimizado.
- Os recursos podem ser **agregados** para facilitar aplicações com uso intensivo de dados (data-intensive).
- A partilha de dados favorece atividades colaborativas. Muitas aplicações atuais aplicam diferentes análises sobre o mesmo conjunto de dados...
- Elimina ou reduz substancialmente o investimento inicial para uma infraestutura computacional, bem como o custo fixo de funcionamento.
- Redução de custo: agregação e partilha de recursos permite a abordagem **pay as you go**.
- Elasticidade: capacidade de responder a situações de carga irregulares, para mais ou menos, com eficiência.
- Conveniência: virtualização permite ao utilizador o uso de um ambiente que lhe é familiar, em vez de obrigar ao uso de novas ferramentas e protocolos.

#### Fatores que contribuem para o sucesso do paradigma de computação em nuvem
- Mais capacidade para tirar partido de avanços em software, tecnologias de redes, armazenamento e processamento, através das empresas que prestam serviços em nuvem.
- Cloud assenta numa infraestrutura homogénea (hardware + software).
- Os recursos estão no âmbito de um só administrative domain (AD). Segurança, gestão, tolerância a falhas, e QoS (qualidade do serviço) tornam-se menos complexas, em comparação com um ecossistema heterogéneo e múltiplos ADs.

#### Terminologia relacionada
- Centralized computing
	- All resources in one physical system.
- Parallel computing
	- All processors are either tightly couple with central shared memory or loosely coupled with distributed memory
- Distributed computing
	- Field that studies distributed systems. Consists of multiple autonomous computers, each with its own private memory communicating over a network.
- Cloud computing
	- internet cloud of resources that may be either centralized or decentralized.

#### Desafios
- Disponibilidade.
- Demasiada variedade.
- Risco de estrangulamento por sobrecarga de dados.
- Imprevisibilidade do desempenho.
- Gestão de recursos.
- Segurança e Confidencialidade.

### SaaS - Software-as-a-Service
- Aplicações são disponibilizadas pelo CSP como um serviço.
- Utilizador não gere a infraestrutura subjacente nem a fonte do software da aplicação.
- Não adequado para situações em que os dados não podem ser externalizados.

### PaaS - Platform-as-a-Service
- O utilizador da nuvem pode implantar aplicações suas, desde que compatíveis com linguagens de programação e outras ferramentas do fornecedor (CSP).

### IaaS - Infrastructure-as-a-Service
- O utilizador pode implantar e executar qualquer software, incluindo aplicaçõe e sistemas operativos (server hosting, web servers, storage...).

## Protection levels
- 0 -> highest protection level privilege and it is in this ring that the operating system kernel normally runs
	- Code executing in ring 0 is said to be running in system space, kernel mode or supervisor mode.
	- All other code such as applications running on the operating system operates in less privileged rings, typically ring 3.

## Virtualization of x86 architecture
Ring de-privileging
- a VMMs forces the operating system and the applications to run at a privilege level greater than 0.

Ring aliasing
- a guest OS is forced to run at a privilege level other than that it was originally designed for.

Address space compression
- a VMM uses parts of the guest address space to store several system data structures.

Non-faulting access to privileged state
- several store instructions can only be executed at privileged level 0 because they operate on data structures that control the CPU operation. They fail silently when executed at a privilege level other than 0.

Interrupt virtualization
- in response to a physical interrupt, the VMM generates a virtual interrupt and delivers it later to the target guest OS which can mask interrupts.

Access to hidden state
- elements of the system state, descriptor caches for segment registers, are hidden; there is no mecanism for saving and restoring the hidden components when there is a context switch from one VM to another.

Ring compression
- paging and segmentation protect the VMM code from being overwritten by guest OS and applications.

## Padrões para o fluxo de execução distribuída
1. Sequence
	- several tasks have to be scheduled one after the completion of the other.
2. AND split
	- both tasks B and C are activated when task A terminates.
3. Synchronization
	- task C can only start after tasks A and B terminate.
4. XOR split
	- after completion of tas A, either B or C can be activated.
5. XOR merge
	- task C is enabled when either A or B terminate.
6. OR split
	- after completion of task A one could activate either B, C or both.
7. Multiple merge
	- once task A terminates, B and C execute concurrently. When the first of them, say B, terminates, then D is activated. Then, when C terminates, D is activated again.
8. Discriminator
	- wait for a number of incoming branches to complete before activating the subsequent activity. Then wait for the remaining branches to finish without taking any action until all of them have terminated. Next resets itself.
9. N out of M join
	- barrier synchronization. Assuming that M tasks run concurrently, N (N < M) of them have to reach the barrier before the next task is enabled. In our example, any two out of the three tasks A, B and C have to finish before E is enabled.
10. Deferred choice
	- similar to the XOR split but the choice is not made explicitly. The run-time environment decides what branch to take.

## MapReduce philosophy
1. An application starts a master instance, M worker instances for the Map phase and later R worker instances for the Reduce phase.
2. The master instance partitions the input data in M segments.
3. Each map instance reads its input data segment and processes the data.
4. The results of the processing are stored on the local disks of the servers where the map instances run.
5. When all map instances have finished processing their data, the R reduce instances read the results of the first phase and merge the partial results.
6. The final results are written by the reduce instances to a shared storage server.
7. The master instance monitors the reduce instances and when all of them report task completion the application is terminated.

## Nomes compostos
**URI**
- Uniform Resource Identifier
**URL**
- Uniform Resource Locator
	- esquema (http, mail, ftp), hostname e pathname até ao documento.
	- problema dangling skills: se o objeto é movido podem ficar apontadores inválidos.
**URN**
- Uniform Resource Name
	- identificador persistente, mesmo que o recurso mude de localização

# Resolução de frequências
## 2º Frequência Sistemas Distribuídos
1. No contexto de cloud computing, qual o impacto da virtualização na previsibilidade e desempenho do serviço? E o uso de recursos?
	- A virtualização simplifica a gestão de recursos físicos relacionados com interpretadores, memória e comunicação, e permite ao utilizador o use de ambiente que lhe é familiar, em vez de obrigar ao uso de outros distintos ao que estão habituados. Esta impacta o desempenho e a previsibilidade ao permitir a migração de aplicações de uma plataforma para outra.

2. Quais os desafios de cloud computing?
	- Os desafios de cloud computing são: a disponibilidade do serviço, a variedade de serviços, estruturas e modelos de dados, a confidencialidade de dados e auditabilidade, o risco de estrangulamento por sobrecarga de dados, a imprevisibilidade do desempenho, as gestão de recursos e a segurança.

3. O que entende por microsserviços? Que tecnologias utilizadas nas aulas práticas podem ser usadas neste contexto?
	- Microsserviços são uma abordagem de design de software em que uma aplicação é dividida em pequenos serviços independentes, cada um focado em executar uma tarefa específica. Cada microsserviço opera como uma entidade autónoma, comunicando-se com outros microsserviços através de interfaces bem-definidas, geralmente através de protocolos de comunicação como HTTP/REST ou mensagens assíncronas.

4. Para comunicação entre processos, como compara web services com REST services?
	- Para comunicação entre processos, podemos dizer que os REST services são mais leves que os web services, podem ser considerados intelegíveis e os formatos dos dados podem ser JSON ou XML mantendo assim a flexibilidade. Em REST cada objeto tem um estado atribuído, e a representação do mesmo é transportada por pedidos HTTP.

5. Refira os tipos de virtual machines que conhece?
	- Os tipos de virtual machines/hypervisors que conheço são: tipo 1 em que um "guest" OS executa diretamente numa certa plataform, e o tipo 2 em que o "guest" OS executa sobre um OS principal.

6. O que é um web service?
	- Um web service é uma camada de software para facilitar a interação entre cliente e servidor, tornando-a mais rica e mais estruturada. Incluem uma API que permite aceder a serviços remotos através da rede.

7. Na escolha de Container ou Virtual Machine, quais os aspetos a ter em conta?
	- Em relação às virtual machines os containers permitem concentrar mais carga computacional na mesma plataforma, requerem menos tempo para arranque de uma solução, são mais flexíveis e é mais fácil especificar um ambiente de execução. No entanto a partilha da infraestrutura subjacente pode trazer desafios como a imprevisibilidade do desempenho e esgotar os recursos partilhados. Contrariamente as virtual machines são mais dinâmicas, o que torna o seu desenvolvimento mais simples, quase como se de um simples computador se tratasse. As virtual machines ainda apresentam a vantagem de poderem guardar o seu estado, podendo ser replicadas ou transferidas para outras máquinas.

8. O que entende por resolução de nomes com navegação controlada por servidor? Distinga serviço de nomes de serviços de diretoria.
	- A resolução de nomes controlada pelo servidor ocorre quando um cliente tenta resolver um nome e o servidor faz a procura desta resolução. Esta resolução pode ser recursiva, ou não recursiva (de modo iterativo ou multicast). Na pesquisa recursiva, o cliente realiza o pedido de resolução de nomes e o servidor tenta resolver esse nome e no caso de não conseguir, pede a outro servidor para o tentar resolver, no caso de este falhar, irá recorrer a outro servidor para tentar resolver o nome, quando o nome for resolvido, este irá percorrer o caminho inverso até chegar ao cliente. Na pesquisa não recursiva, o cliente faz o pedido e o servidor faz a comunicação com os restantes servidores para que estes tentem resolver o nome.
	- Os serviços de nome oferecem uma camada de abstração que permite que os componentes do sistema usem nomes simbólicos em vez de lidar diretamente com endereços físicos.
	- Os serviços de diretoria guardam associações entre nomes e atributos, e permite pesquisa de entradas baseada nos atributos.

## so2 - freq 2(2).txt
1. Descreva dois tipos de Uniform Resource Identifier (URI), apontando as caracteristicas chaves de cada.
	- URL (Uniform Resource Locator) tem um esquema (http, mail, ftp), hostname e pathname até ao documento. Tem problemas em dangling links, se o objeto é movido podem ficar apontadores inválidos.
	- URN (Uniform Resource Name) é um identificador persistente, mesmo que o recurso mude de localização, regista-se o nome (URN), incluindo atributos do documento (o seu URL, ...), se o URL mudar basta atualizar o URL registado para aquele URN e a pesquisa faz-se pelo URN e resulta sempre no URL correto.

2. Diga o que entende por “resolução de nomes”.
	- A resolução de nomes é o processo em que se apresenta um nome a um contexto, que tem um binding direto desse nome num conjunto de atributos, ou efetua a procura de um binding num outro contexto.

3. Há alguma funcionalidade nos serviços de directoria que não exista nos serviços de nomes? Comente.
	- Nos serviços de nomes existem pares (nome, atributos) e a pesquisa efectua-se pelo nome mas em determinados cenários pode interessar a pesquisa pelos atributos, enquanto que o serviço de directoria guarda associações (bindings) entre nomes e atributos e permite pesquisa de entradas baseada nos atributos, logo podemos afirmar que os serviços de diretorias têm mais funcionalidades que os serviços de nomes.

4. Que razões poderão motivar o uso de replicação num sistema distribuído?
	- Num sistema distribuído espera-se que os serviços tenham alta disponibilidade, a melhor performance possível e que o efeito das falhas seja mínimo, assim replicação é fundamental, na medida em que contribui para a performancem, alta disponibilidade e tolerância a falhas.

# coisas
Web services
- camada de software para facilitar a interação entre cliente e servidor, tornando-a mais rica e mais estruturada. Incluem uma API que permite aceder a serviços remotos através da rede.
- servem de suporte à computação distribuída na internet, facilitando a cooperação de aplicações baseadas em diferentes linguagens.
- diferença relativamente ao Object Model distribuído: um web service é assegurado por um único objeto
	- o garbage collection neste caso não é tão crítico, porque não expõe objetos a referências remotas.
	- a referência remota para o objeto não é relevante.
	- para lá do web service podem existir muitos objetos

SOAP - Simple Object Access Protocol
- extensão de XML-RPC
- é um protocolo para troca de mensagens, usualmente sobre HTTP, que trata do correto encapsulamento dos dados em XML.
- possíveis protocolos para envio das mensagens HTTP, SMTP, TCP, UDP
- não levanta problemas na presença de firewalls
- Uso de XML em SOAP e nos dados:
	- vantagem: mais legível, por humanos
	- desvantagem: processamento mais lento que formatos binários.

UDDI - Universal Description Discovery and Integration
- protocolo para publicar e pesquisar meta-informação sobre web services... permite que uma aplicação descubra e use um web service em tempo de execução.

Assumindo que se começa por desenvolver a Service Interface e a sua implementação
- o Skeleton e a descrição do serviço em WSDL são gerados automaticamente.
- o serviço vai correr num Servlet Container
- depois de preparado, o web service deve estar num ficheiro .war
- é possível gerar a classe do proxy, para o cliente, em runtime, a partir da service description.

GRID Computing
- middleware desenhado para permitir e optimizar a partilha de recursos em larga escala.
- usualmente para utilizadores que necessitam de processar grande quantidades de dados (cientistas).
- recursos alojados em computadores de diferentes plataformas, ambiente heterogéneo.
- pode assentar em Web Services.

Motivações da Cloud
- uso mais geral.
- vocação para os serviços.
- virtualização.
- alocação de recursos dinâmica em função das necessidades

REST - Representational State Transfer
- Arquitetura para interação em sistemas distribuídas.
- Objetos têm estado, cuja representação é transportada por pedidos HTTP (PUT, GET, POST, DELETE)
- **VS SOAP**
	- mais leve
	- ainda intelegível
	- formato dos dados pode ser JSON ou XML

Microsserviços
- Uma abordagem de desenvolvimento de software que separa as tarefas de um processo complexo num conjunto de serviços e processos autónomos, que comunicam através de APIs, cooperando para a realização de um serviço composto.
- **VS sistemas monolíticos**
	- maior agilidade
	- facilitam manuntenção de software
	- promovem a modularização e conformidade com normas e APIs
	- facilitam alterações à arquitetura, permitindo escalar de modo mais eficaz

Cloud Computing
- uso de recursos computacionais disponibilizados como um serviço, através da rede.
- Características fundamentais
	- Autoatendimento na hora e em função da necessidade
	- Acesso com grande largura de banda
	- Resource pooling
	- Elasticidade
	- Mensurabilidade do serviço
- Segurança e manuntenção ficam a cargo dos fornecedores (CSP - Cloud Service Provider).

Elastic Computing
- capacidade de ativar dinamicamente o acesso a recursos computacionais, de modo a responder a uma carga variável.

Armazenamento dos dados
- Perto do site que precisa deles
- junto à ligação de rede de alta velocidade
- facilita acessos com origem em diversas localizações

Tipos de cloud
- Pública
	- infraestrutura disponibilizada ao grande público, operada por um consórcio
- Privada
	- operada por uma só organização
- Comunitária
	- partilhada por várias entidades
- Híbrida
	- combinação de um ou mais tipos

Benefícios de cloud computing
- recursos partilhados
- espera-se que o pico de solicitações não ocorra ao mesmo tempo, uso global dos recursos é otimizado
- recursos podem ser agregados para facilitar aplicações com uso intensivo de dados
- partilha de dados favorece atividades colaborativas
- elimina ou reduz o investimento inicial
- redução de custo, pay as you go
- elasticidade
- conveniência, virtualização permite ao utilizador o uso de um ambiente que lhe é familiar

Desafios
- Disponibilidade
- Variedade de serviços
- Segurança, confidencialidade e auditabilidade
- Risco de estrangulamento, data transfer bottleneck
- Imprevisibilidade do desempenho
- Gestão de recursos

Saas
- Aplicações são disponibilizadas pelo CSP como um serviço

PaaS
- O utilizador da nuvem implanta aplicações, desde que compatíveis com linguagens de programação e ferramentas do CSP

IaaS
- User pode implantar e executar qualquer software, incluindo aplicações e OSs

Multiplexing
- criar múltiplos objetos a partir de uma só instância de objeto físico

Agregação
- criar um recurso virtual a partir de vários objetos físicos/reais

Emulação
- formar um objeto virtual, do tipo A, a partir de um objeto físico de tipo B

Multiplexing e emulação
- como exemplo da memória virtual com paginação para memória real ou disco; um endereço virtual emula um endereço real

Type 1 hypervisor
- executa diretamente numa certa plataforma, um "guest" OS executa no segundo nível acima do hardware.

Type 2 hypervisor
- executa sobre um OS, um "guest" OS executa no terceiro nível acima do hardware.

VM
- ambiente isolado que aparente ser um PC completo, no entanto tem apenas acesso a parte dos recursos da máquina.

Virtualization examples
- recuperação de desastre
- teste e treino
- workspaces portáteis

Desvantagens/riscos da virtualização
- as proteções num determinado nível/camada podem ser ultrapassadas por malware em camada inferior.
- Pode existir um VMM Rootkit entre o hardware e o SO

Containers
- recursos para alojar aplicações
- forma mais leve de virtualização orientada para aplicações
- isolamento
- portabilidade

VMs VS Containers
- Pontos a favor dos containers
	- permitem concentrar mais carga computacional na mesma plataforma
	- requerem menos tempo para arranque de uma solução
	- flexibilidade
	- maior facilidade para especificar um ambiente de execução
- Desafios
	- a partilha da infraestrutura subjacente pode trazer desafios
		- imprevisibilidade do desempenho
		- esgotar recursos partilhados

Desafios no desenvolvimento de aplicações
- gestão de desempenho
- fiabilidade
- variabilidade na latência e largura de banda disponível
- compromisso entre o detalhe de data logging e a capacidade de identificar causa de erros

Opções de comunicação
- RPC (remote procedure calls)
- SOAP (simple object access protocol)
- REST (representation state transfer) - permite a transmissão entre stateless servers, independente de plataforma e linguagens de programação

Com computação em nuvem
- grandes infraestruturas
- acesso on-demand
- processos com uso intensivo de dados
- novos paradigmas de programação com distribuição

Serviços de nomes
- fornecem informação sobre objetos a partir do seu nome
- relacionados com os serviços de diretorias e discovery services
- armazenam um ou mais contextos de nomes
- operações:
	- resolver um nome
	- adicionar, listar e apagar binding ou contextos

Resolver um nome
- obter informação associada a um nome, necessária para efetuar uma operação

Binding
- associação entre nome e objeto
- em geral entre nome e atributos do objeto
	- atributo: propriedade do objeto, que tem um valor

Contexto
- conjunto de bindings

Endereços
- nomes que também são resolvidos (ARP requests) para MAC address

URI -> URL
- esquema (http, mail, ftp), hostname e pathname até ao documento
- problema dangling links: se o objeto é movido podem ficar apontadores inválidos

URI -> URN
- identificador persistente
- regista o nome (URN), incluindo atributos do documento: o seu URL

Espaço de nomes
- conjunto de todos os nomes válidos para determinado serviço e que obedecem a regras sintáticas específicas

Aliases
- nomes alternativos

Resolução de nomes
- processo em que se apresenta um nome a um contexto, que tem um binding direto desse nome num conjunto de atributos, ou efetua a procura de um binding num outro contexto
- com os aliases pode haver ciclos

Navegação
- Controlada pelo cliente
	- iterativa
		- se um servidor não tem resposta liga-se ao seguinte
	- multicast
		- o cliente faz um multicast com o nome a resolver para um grupo de servidores. O servidor que tem a informação responde com unicast
- Controlada pelo servidor
	- não recursiva
		- de modo iterativo ou multicast
	- recursiva

Cache
- DNS: clientes e servidores costumam ter uma cache; ajuda a manter boa performance

MapReduce
- Framework para computação paralela distribuída
- mapping a function f over a sequence x y z
	- yields f(x) f(y) f(z)
- reduce combines sequences of elements using a binary op
- many data analysis computations can be expressed as:
	- applying a map operation to each logical input record
	- produce a set of intermeadiate (key, value) pairs
	- applying a reduce to all intermidiate pairs with same key

Basicamente
- a função map processa um registo de cada vez, e de modo independente (map square (1 2 3 4) -> (1 4 9 16))
- a função reduce processa o conjunto de todos os registos em grupos, usando um operador (reduce + (1 4 9 16) -> (1+4+9+16) = 30)

Apache Hadoop
- framework distributed processing of large data sets, across clusters of computers, using simple programming models (OS implementation of MapReduce)

## Perguntas ChatGPT
1. O que é um Web Service e qual é o propósito principal por trás do seu uso em sistemas distribuídos?
	- Um web service é uma camada de software que facilita a interação entre cliente e servidor, tornando-a mais rica e estruturada, também incluem uma API que permite aceder a serviços através da rede. Estes permitem que diferentes plataformas comuniquem entre si de forma eficiente, sendo este o seu propósito principal.

2. Explique a diferença entre serviços RESTful e serviços web baseados em SOAP.
	- Os serviços RESTful em comparação com os serviços web baseados em SOAP, são mais leves, ainda podem ser considerados intelegíveis e suportam, para além de XML, o JSON como linguagem de comunicação. Os serviços RESTful comunicam através de métodos HTTP, enquanto que os serviços SOAP comunicam através do protocolo SOAP.

3. Quais são as vantagens e desvantagens da arquitetura de microsserviços em comparação com monolitos?
	- As vantagens da arquitetura de microsserviços em comparação como monolitos são: a sua escalabilidade, visto que utilizando um sistema de microsserviços podemos escalar cada serviço individualmente, enquanto que num sistema monolito não temos essa separação; a sua resiliência e tolerância a falhas, no sentido em que se um serviço falha, isso não afeta necessariamente toda a aplicação; a facilidade de manuntenção e atualizações, como a aplicação está dividida em vários serviços, não requer necessariamente a paragem da aplicação para fazer a atualização; e por fim, temos a flexibilidade tecnológica, ou seja, cada serviço pode ser desenvolvido usando tecnologias diferentes. No entando, a arquitetura de microsserviços também tem desvantagens, como a complexidade na gestão da comunicação entre serviços, visto que estes podem ser desenvolvidos em tecnologias diferentes, a necessidade de lidar com a consistência dos dados em ambientes distribuídos e por fim, a sobrecarga de gerir múltiplos serviços em produção.

4. Como é que é alcançada a independência de implantação numa arquitetura de microsserviços?
	- A independência de implantação numa arquitetura de microsserviços é alcançada através da possibilidade de implantar, atualizar e escalar cada serviço de forma independente, sem afetar os restantes serviços.

5. Defina cloud computing e liste os principais modelos de serviço oferecidos pelos fornecedores de nuvem.
	- Cloud computing refere-se a um modelo de fornecimento de serviços de computação pela internet. Em vez de possuir e manter servidores e infraestruturas local e fisicamente, o utilizador pode aceder a recursos computacionais, como armazenamento, processamento e software através da internet. Os principais modelos de serviço oferecidos pelos CSPs/fornecedores são: IaaS (Infrastructure-as-a-Service), PaaS (Platform-as-a-Service) e SaaS (Software-as-a-Service).

6. Como é que a escalabilidade automática beneficia os utilizadores em ambientes de nuvem?
	- A escalabilidade beneficia os utilizadores em ambientes de nuvem no sentido em que, disponibiliza recursos, seja de armazenamento ou processamento, à medida que o utilizador necessita, fazendo com que este apenas pague pelo que utiliza e evitando a necessidade de intervir manualmente sempre que precisar de mais ou menos recursos.

7. Explique o conceito de virtualização e como ele difere de uma máquina virtual.
	- Virtualização é um processo que permite a utilização eficiente de hardware computacional, esta usa software para criar uma camada de abstração sobre o hardware de um computador que permite que os elementos do mesmo (memória, processador...) sejam dividos em vários computadores virtuais, normalmente chamados de máquinas virtuais. Uma máquina virtual é um ambiente virtualizado que simula um computador físico em forma de software.

8. Quais são os benefícios da virtualização em termos de eficiência de recursos e isolamento?
	- Em termos de eficiência de recursos a virtualização permite que aplicações sejam executadas cada uma na sua VM, sem sacrificar a fiabilidade do sistema e assegurando que cada aplicação tem acesso a todos os recursos que necessita. Em termos de isolamento, a virtualização cria uma camada de segurança, pois caso aconteça alguma coisa à VM, como por exemplo, seja atacada por um vírus, é possível fazer um rollback daquela VM até ao momento antes de ser atacada, e como esta está isolada do sistema operativo principal, este não será afetado pelo vírus.

9. Qual é a diferença fundamental entre máquinas virtuais e containers?
	- A diferença fundamental entre máquinas virtuais e containers é que as máquinas virtuais reproduzem todo o hardware do computador, e cada máquina virtual irá executar um OS inteiro, o que causa a repetição de código desnecessário. Os containers, por outro lado, apenas executam uma aplicação e as coisas de que esta aplicação depende, como bibliotecas de software e variáveis de sistema.

10. Como é que os containers facilitam a implantação consistente de aplicações em diferentes ambientes?
	- Os containers facilitam a implantação consitente de aplicações em diferente máquinas, através do empacotamento de bibliotecas de software, código e dependências num únicos container, tornando-os portáteis e mais leves que as máquinas virtuais.

11. O que é um serviço de nome e como é que este facilita a comunicação em sistemas distribuídos?
	- Um serviço de nome refere-se a uma função ou sistema que atribui e gere nomes para identificar recursos numa rede de computadores. O serviço de nomes atribui um nome legível a um endereço físico, fazendo com que os componentes de um sistema distribuído não tenham de lidar com endereços físicos complexos, facilitando assim a comunicação.

12. Explique a diferença entre um serviço de nome e um serviço de diretoria.
	- Um serviço de nome oferece uma camada de abstração em que permite que os componentes do sistema usem nomes simbólicos em vez de endereços físicos, enquanto que os serviços de diretoria estabelecem relações entre estes nomes simbólicos e atributos, como o URL, chamados bindings, e permitem a pesquisa de entradas baseadas nos atributos, também fornece informações adicionais além da resolução de nomes.