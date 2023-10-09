# Resumo

## Características de um Sistema Distribuído
### Conceitos relacionados com Paralelismo

- Multiprocessor systems
    - Memória partilhada
    - Bus-based interconnection network
    - E.g. SMPs (symmetric multriprocessors) with two or more CPUs
- Multicomputer systems
    - Memória não partilhada
    - Tipicamente homogéneos em hardware e software
    - Massively Parallel Processors (MPP)
        - Tightly coupled high-speed network
    - PC/Workstation clusters
        - High-speed networks/switches based connection
        - A extensibilidade dos clusters dá lugar a alguma heterogenidade
            - Introdução de PCs comuns, de características diversas...

Computação paralela - Uso simultâneo de múltiplos recursos computacionais para resolver um problema.

Programação paralela - Concepção de um programa para executar computação paralela.

Sistemas distribuídos:
- Escalam mais que sistemas convencionais
- Menos dependentes de hardware especializado
- A programação destes sistemas é complexa

### Características de um Sistema Distribuído
Um sistema distribuído é aquele em que os seus componentes estão distribuídos por uma rede de computadores, comunicam e coordenam as suas ações através de troca de mensagens, e funciona para o utilizador como se de um sistema elementar se tratasse.

- Pode haver concorrência
- Não existe um relógio global
- Podem surgir falhas isoladas

### Alguns conceitos

- Serviço
    - uma funcionalidade a disponibilizar, que normalemente envolve uso de alguns recursos

- Servidor
    - um programa em execução num computador
    - aceita pedidos de outros computadores para prestar um serviço

- Cliente
    - programa que faz pedidos ao servidor

- Processo
    - uma instância de um programa em execução. Compreende um ambiente de execução e uma ou mais threads

- Thread
    - uma abstração do SO para um tarefa ou atividade

- Sistema aberto
    - um sistema que pode ser estendido em termos de componentes ou funcionalidades sem perturbação de operações existentes

### Características de um SD
- heterogeneidade
- abertura
- segurança
- escalabilidade
- resolução de falhas ou problemas
- concorrência
- transparência

### Abstrações
... são familiares ao programador
- Ajudam a simplificar um problema
- Vários níveis
- Os níveis superiores usam interfaces para as operações de níveis inferiores

A distribuição tem implicações
- Ausência de memória partilhada
- Ausência de relógio global...
- Concorrência
- Falhas
- Dificuldades de coordenação

### Modelo físico
- Representação da camada de hardware onde assenta todo o sistema distribuído
    - Identifica os diferentes computadores e outros dispositivos pertencentes ao sistema e o modo como estes estão interligados
    - Sem detalhes de tecnologia
- Modelo físico mínimo
    - Conjunto de computadores interligados por rede

Gerações de modelos
- Iniciais
    - redes locais, PCs e impressoras...
- Escala global/Era da Web
    - desde 1990's; redes de redes; PCs e servidores (fixos)
- Contemporâneo
    - nós podem ser notebooks ou smartphones; mobilidade

### Dificuldades e ameaças nos SD
- variados modos de utilização
    - distintas necessidades
        - capacidade de processamento
        - volume de informação

- grande variedade de ambientes
    - heterogeneidade de hardware, sistemas operativos, redes e respetivos protocolos

- problemas internos
    - sincronização de relógios, falhas de hardware ou software, incoerência decorrente de concorrência

- problemas externos
    - ataques à integridade, confidencialidade, denial of service

### Spontaneous networking

A forma de interação automática entre dispositivos móveis e outros dispositivos inseridos numa rede ou ambiente distribuído.

Aspetos chave:
- Facilidade de associação a uma rede local, de preferência sem fios
    - Conectividade limitada
        - Dificuldades inerentes à mobilidade
        - Capacidade reduzida dos equipamentos terminais
    Aspetos de segurança e privacidade
- Facilidade de integração com serviços locais
    - Discovery Services
        - Registration Service + Lookup Service

### Modelos de Análise Fundamental

Propósito:
- realçar aspetos de desenho, dificuldades e ameaças a considerar no desenvolvimento de SD, de modo que estes possam desempenhar a sua tarefa de modo correto, fiável, eficiente e seguro.

- Interação: análise de aspetos relacionados com o desempenho e a dificuldade de estabeler limites temporais num SD, associados à comunicação e coordenação entre processos.

- Falhas: especificação exatas das falhas que poderão surgir em processos, dispositivos ou canais de comunicação/rede

- Segurança: análise das possíveis ameaças a processos e canais de comunicação/rede (ataques internos e externos)

### Modelo de interação
Algoritmo - sequência de passos a executar para completar uma tarefa

Algoritmo Distribuído - sequência de passos a executar por cada um dos processos do sistema, incluindo a transmissão de mensagens (de dados e de coordenação) entre os mesmo, para completar uma tarefa

1. Batch processing systems
    - throughput
2. Online systems (respondem na hora)
    - tempo de resposta
        - envolve: tempo de serviço + latência

Jitter - variação no tempo necessário para o envio/entrega de fragmentos de dados de uma mesma mensagem.

Clock drift rate - taxa de desvio do tempo face a uma referência correta.

SD Síncronos: existem limites para:
- tempo de execução de cada passo de um processo
- tempo até à recepção de uma mensagem enviada
- clock drift rate (conhecido) em cada máquina

SD Assíncronos: não há limite defindo ou garantias para:
- velocidade de execução de um processo
- tempo de transmissão de uma mensagem, pode ter atraso (delay)
- clock drift rate: a taxa é arbitrária

**Sistema linearizável**
- Ordenação total das operações: é sempre possível determinar a sequência cronológica entre quaisquer operações, usualmente não coincidente com um ambiente concorrente comum

**Sistema com ordenação causal**
- Ordenação parcial
- Duas operações são consideradas concorrentes se não se pode dizer que uma aconteceu antes da outra
- Dois eventos podem ordenar-se se tiverem uma relação causal

### Lamport
- cada processo incia com um contador a zero
- cada processo incrementa o seu contador se envia uma mensagem, ou se recebe uma ação
- cada envio leva um timestamp
- cada mensagem recebida conduz a um ajuste no contador de destino:
    - localCounter = max(localCounter, messageTS) + 1

### Ordenação lógica de Lamport
- no mesmo processo: a antes de b implica TS(a) < TS(b)
- se p1 envia m a p2, send(m) precede receive(m)
- transitividade: se a precede b e b precede c, então a precede c
- em processos diferentes x e y: TSpx(a) < TSpy(b) não implica que a ocorre anes de b

### Modelo de falhas
- Falhas de omissão
    - quando o processo ou o canal falham no desempenho da tarefa que lhes cabe
        - falhas no processo
            - por crash ou por lentidão
        - falhas no canal de comunicação
            - dropping messages
            - send-omission
            - receive-omission
- Falhas arbitrárias
    - pior cenário
    - falhas diversas... não determinísticas
- Falhas temporais
    - sistemas síncronos: estes erros levam à não entrega de respostas
    - sistemas assíncronos: estes fenónemos acarretam lentidão mas não correspondem necessariamente a falhas temporais, pois não há imposições temporais rígidas

### Modelo de segurança
Identifica possíveis ameaças num sistema distribuído
    - ameaças a processos
        - identidade do interlocutor remoto
        - legitimidade daquele para aceder ao recurso do processo
    - ameaças a canais de comunicação
        - introdução de mensagens forjadas
        - adulteração do conteúdo de mensagens em trânsito

Visa garantir a segurança de objetos, processos e dos canais de comunicação.

### Camada inferior de middleware

- comunicação
- representação externa de dados
- marshaling

- UDP
    - abstração para comunicação entre processos
    - permite o envio de mensagens isoladas, através de pacotes chamados datagramas
- TCP
    - abstração para comunicação entre processos
    - fornece uma ligação bidirecional entre dois processos
- Comunicação: **Operações** envolvidas numa mensagem:
    - send
    - receive
- Existe uma fila-de-espera (buffer) associada ao processo destinatário
    - envio: a mensagem é adicionada à fila remota
    - recepção: a mensagem é retirada da fila local
    
- Comunicação síncrona: os processos emissor e receptor sincronizam-se a cada mensagem
    - send e receive são operações bloqueantes
        - o emissor fica parado no *send* até que o *receive* seja efetuado
        - ao efetuar um *receive*, o receptor fica bloqueado até a mensagem chegar
- Comunicação assíncrona: não há sincronização
    - *send* não é bloqueante
        - o emissor prossegue assim que a mensagem passa ao buffer local de saída
    - *receive* pode ser bloqueante ou não bloqueante*
        - \* o processo com um buffer que será preenchido em background, havendo uma notificação quando isso acontecer

- Porto/Port
    - inteiro, identifica o destinatário da mensagem numa máquina
    - associado a um só destinatário mas usado por vários emissores
    - um processo pode receber mensagens de vários portos
    - um processo não partilha portos com outros processos na mesma máquina
    - uma máquina tem $2^{16}$ números de portos disponíveis


- Comunicação via:
    - datagramas - UDP
    - streams - TCP

# Freq 1 - 2017-2018

## 1) Como descreve o comportamento das primitivas genéricas das comunicações **send** e **receive** relativamente ao bloqueio, em comunicações síncronas e em comunicações assíncronas.

As primitivas genéricas das comunições send e receive em comunição síncrona são operações bloqueantes. Isto é, o emissor fica parado no *send* até que o *receive* seja efetuado, ao efetuar um *receive*, o receptor fica bloqueado até a mensagem chegar. Já nas comunicações assíncronas, o *send* não é uma operação bloqueante, ao contrário do *receive* que pode ou não ser. Neste tipo de comunição, o emissor prossegue assim que a mensagem passa ao *buffer* local de saída, sendo que o processo prossegue com um *buffer* que será preenchido em background, havendo uma notificação quando isso acontecer.


## 2) Considere a afirmação “**Em java RMI, qualquer método da interface remota pode ser invocado, desde objetos pertencentes ao mesmo processo**” concorda? E relativamente à inserção com origem em processos diferentes?

????????????????


## 3) Para comunicação entre processos, como compara **WEB services** com **REST services**?

Em termos de comunicação entre processos, a escolha entre web services e REST services depende dos requisitos específicos do sistema e das preferências de design. Web services são mais flexíveis em relação aos protocolos de comunicação, enquanto os REST services são mais simples e seguem as convençõs da web padrão, tornando-os amplamente adotados em aplicações web e serviços públicos na internet.


## 4) O que entende por resolução de nomes com navegação controlada pelo servidor? Distinga serviço do nome de serviço de diretorias.

- **Resolução de nomes**: Processo de dar um nome legível a um identificador ou endereço que possa ser usado para aceder a um recurso específico dentro de uma rede. Isto é comum em sistemas distribuídos, onde os recursos podem estar em diferentes máquinas ou locais.
- **Navegação controlada pelo servidor**: Navegação é a descoberta de recursos na rede. A navegação controlada pelo servidor significa que um servidor central é responsável por manter informações sobre a localização e o acesso aos recursos na rede.
- **Serviço**: Um "serviço" no contexto de sistemas distribuídos refere-se a uma funcionalidade específica ou um conjunto de operações que podem ser acedidas por outros componentes ou sistemas na rede. Um serviço pode ser qualquer coisa, um *WEB service* que fornece dados, uma função de cálculo ou até um serviço de diretoria que gere informações de localização.
- **Nome de serviço de diretorias**: O nome de serviço de diretorias refere-se ao nome ou identificador associado a um serviço específico num sistema de diretorias. Num sistema de resolução de nomes com navegaçã controlado pelo servidor, esses nomes são usados para mapear uma solicitação de serviço à localização real do serviço na rede.

R: A resolução de nomes com navegação controlada pelo servidor é um processo que envolve a procura de recursos ou serviços na rede através de um servidor central que mantém informações sobre a localização desses recursos. O nomo de serviço de diretorias é o identificador usado para mapear solicitações de serviços para a sua localização real num sistema de diretorias. Isto permite que sistemas distribuídos encontrem e acedam aos recursos de maneira eficiente e escalável.

## 5) Descreva um algoritmo de autenticação baseado em tickets. Um ticket é (?) ou é encriptado? E com que chave?

--

## 1) Explique como o Middleware simplifica a tarefa de desenvolvimento de aplicações distribuídas.

O middleware simplifica a tarefa de desenvolvimento de aplicações distribuídas, fornecendo uma camada de abstração que lida com a complexidade da comunicação e da coordenação entre sistemas distribuídos.

## 2) Comunicação síncrona e assíncrona

Comunicação síncrona:
- send e receive são operações bloqueantes
    - o emissor fica parado no send até que o receive seja efetuado
    - ao efetuar um receive, o receptor fica bloqueado até a mensagem chegar

Comunicação assíncrona:
- send não bloqueante
    - o emissor prossegue assim que a mensagem passa ao buffer local de saída
- receive pode ou não ser bloqueante
    - o processo prossegue com um buffer que será preenchido em background, havendo uma notificação quando isso acontecer

## 3) Interesse de usar uma representação externa de dados? Apontar dois formatos possíveis para tal representação, indicando vantagens e desvantagens de cada um.

O uso de uma representação externa de dados é benéfico em situações em que diferentes sistemas precisem de compartilhar informações ou comunicar entre de si de maneira eficaz. Uma representação externa de dados é uma maneira de estruturar os dados de forma a que possam ser interpretados e processados de forma consistente, independentemente do sistema que os produziu ou que os está a receber. Dois formatos possíveis para tal representação são: JSON e XML. As vantagens do JSON são as seguintes: leve, fácil de ler e escrever e elevado suporto a tipo de dados; as suas desvantagens são: limitado em metadados e falta de suporte. As vantagens do uso de XML são: a sua estrutura hierárquica, o suporte a metadados e a possibilidade de definir esquemas de validação; as suas desvantagens são: é mais pesado que o JSON e a sua complexidade de análise também é mais elevada.

## 4) Medidas que podem ser implementadas a nível aplicacional para aumentar a fiabilidade, superando eventuais falhas de omissão, com a semântica de invocação "at-most-once", isto tudo no uso do protocolo Request-Reply sobre UDP que pode ter riscos de ocorrência de falhas de omissão.

Alguns exemplos de medidas que podem ser implementadas a nível aplicacional para aumentar a fiabilidade são: Implementação de timeouts no lado do cliente para monitorar respostas do servidor, caso o servidor não responda antes do timeout, será enviada novamente a mensagem; Implementação de um sistema de ACKs do lado do servidor, quando este recebe a mensagem envia um ACK ao cliente, caso o cliente não receba o mesmo, poderá enviar novamente a mensagem; Implementação de logs, tanto de envio como de recepção de mensagens.

## 6) Papel desempenhado pelo Skeleton de um objeto remoto.

O Skeleton é o que representa um objeto remoto, este implementa os métodos na interface remota, mas efetuando unmarshall a argumentos no pedido, invocando o método no objeto remoto (localmente) e devolvendo o marshall do resultado e eventual excepção na reposta ao proxy.

## 7) Em RMI, quais os cuidados a ter no Garbage Collection a nível distribuído que não se colocam não distribuído? Explique.

- Garbage Colletion:
    - liberta espaço ocupado por objetos quando eles já não são necessários. 
    - a nível distribuído, é necessário considerar as referências remotas para o objeto.
    - se um objeto tem uma referência local ou remota no conjunto de objetos distribuídos, então deve continuar a existir.
    - Cooperação com o GC local:
        - cada servidor mantém uma lista com o conjunto de processos com referências para os seus objetos
        - quando um cliente cria um Proxy para um objeto, é adicionado ao conjunto de processos com referências para aquele objeto
        - quando o GC do cliente deteta que o proxy do objeto já não é necessário/referido, envia uma mensagem ao servidor (removeRef(O)) e elimina o proxy. O servidor remove o processo da lista
        - quando a lista estiver vazia, o GC do servidor recupera o espaço do objeto, excepto se existirem referências locais

R: Os cuidados a ter no GC a nível distribuído que não se colocam a nível não distribuído são: considerar as referências remotas, se não se tratar de um sistema distribuído, este não irá conter referências remotas; considerar as políticas de GC assíncronas, pois o momento da coleta de lixo pode variar entre máquinas, e os objetos remotos podem ser coletados em momentos diferentes em máquinas diferentes.


## coisas

Representação Externa de Dados (RED) -> formato usado para representação de estruturas e tipos primitivos

- Marshalling
    - tradução das estruturas e tipos primitivos para uma RED adequada para a transmissão. Utilizado para que uma estrutura de dados possa ser usada em RPC ou RMI, ou seja, para que possa ser representado de modo flattened e os tipos primitivos num formato acordado.

- Unmarshalling
    - processo inverso para reconstruir os dados à chegada.

- Diferença entre Marshalling em CORBA e em Java RMI
    - CORBA
        - Em CORBA assume-se que o emissor e receptor conhecem os tipos de cada elemento da mensagem, por isso o tipo não é passado, apenas o valor é passado.
    - Java RMI
        - Em Java RMI a aplicação que recebe a mensagem pode não conhecer o tipo dos dados logo a representação serializada inclui informação sobre a classe do objeto.

- Middleware
    - Vantagens
        - Transparência face à localização
        - Independência dos protocolos de comunicação
        - Independência do Hardware
        - Independência dos Sistemas Operativos
        - Utilização de diferentes linguagens de programação
    - Abstrações
        - RPC (Service Interface)
            - descreve os procedimentos disponíveis e respetivos argumentos (i/o); não se podem passar apontadores como argumentos
        - RMI (Remote Interface)
            - tem os métodos de um objeto que estão disponíveis para Invocação Remota; podem passar-se referências para objetos remotos (diferente de pointers)

- Request-Reply (RR)
    - garantias de doOperation no protocolo RR
        - reenvio do pedido
            - reenviar a mensagem com o pedido para o servidor até a resposta chegar ou se detetar que o servidor está com problemas
        - filtragem de duplicados
            - decidir se o duplicado deve ser processado para reenvio ou ignorado
        - retransmissão de resultados
            - através de um histórico de resultados para evitar uma nova execução da operação
    - medidas usadas por
        - maybe
            - reenvio do pedido -> NÃO
            - filtragem de duplicados -> NÃO
            - executar de novo ou retransmitir resultado do histórico -> NÃO APLICÁVEL
        - at-least-once
            - reenvio do pedido -> SIM
            - filtragem de duplicados -> NÃO
            - executar de novo ou retransmitir resultado do histórico -> EXECUTAR DE NOVO
        - at-most-once
            - reenvio do pedido -> SIM
            - filtragem de duplicados -> SIM
            - executar de novo ou retransmitir resultado do histórico -> RETRANSMITIR RESULTADO DO HISTÓRICO

    - Caso estejão envolvidas operações idempotentes, a semântica de invocação mais apropriada é a semântica Maybe.

- Um sistema baseado em diferentes linguagens de programação e plataformas deve utilizar o mecanismo de invocação remota CORBA, pois este permite a invocação de métodos em servidores escritos em linguagens diferentes.
    - Ainda assim, seria necessário uma Interface Definition Language (IDL) devido ao mecanismo CORBA necessitar da notação para as interfaces que poderão ser usadas pelas diferentes aplicações.

- Em Java RMI, as operações que devem ser obrigatoriamente efetuatas pela aplicação Servidor, para que um cliente possa invocar métodos remotamente sobre o objeto remoto que presta um serviço, são: o proxy, as classes dispatcher e skeleton, ter as classes com implementação para todos os objetos remotos que podem ser a Servant ou Impl, cria e incializar pelo menos um objeto remoto, registar o objeto no binder e assegurar que cada invocação remota é tratada numa nova thread.

- O papel de...
    - Proxy
        - o papel do proxy é tornar a invocação remota transparente para o cliente, fazer o marshalling de argumentos, unmarshalling de resultados de invocação, é único para cada objeto remoto que seja referenciado e implementar os métodos da interface remota do objeto, mas cada método faz marshall da referência do objeto, methoId, e argumentos, aguardando a resposta para o unmarshall.
    - Dispatcher
        - o dispatcher é único para cada classe de objeto remoto, no servidor. O seu papel é receber as mensagens e pelo methodId selecionar o método apropriado no Skeleton.
    - Skeleton
        - o skeleton é único por cada classe de objeto remoto, no servidor. O seu papel é implementar os métodos na interface remota, mas efetuando marshalling a argumentos no pedido, invocando o método no objeto remoto (localmente) e devolvendo o marshall do resultado e eventual excepção na resposta ao proxy.

- Distinga os modos de sincronização interna e externa de relógios num sistema.
    - Relógios sincronizados de modo interno não estão necessariamente sincronizados de modo externo, ou seja, se cada nó de um sistema está sincronizado de modo externo (com a mesma fonte) com limite D, então esse sistema está internamente sincronizado com um limite 2D.

- GC no Object Model Distribuído
    - Algoritmo de Garbage Collection (GC) no Object Model Distribuído
        - Cada servidor mantém uma lista com o conjunto de processos com referências para os seus objetos, quando um cliente cria um proxy para um objeto, é adicionado ao conjunto de processos com referências para aquele objeto. Quando o GC do cliente deteta que o proxy do objeto já não é necessário/referido, envia uma mensagem ao servidor (removeRef(O)) e elimina o proxy. O servidor remove o processo da lista. Quando a lista estiver vazia, o GC do servidor recupera o espaço do objeto excepto se existirem referências locais.
    - Vulnerabilidades do algoritmo face a falhas no cliente
        - o servidor (com objetos remotos) atribui um intervalo de tempo (lease) ao cliente, a contagem é válida até o tempo expirar ou o cliente pedir removeRef()
        - o cliente é responsável por renovar periodicamente o seu lease e assim ser contabilizado na lista de processos com referências para os objetos remotos