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