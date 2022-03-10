## Classloader Version S4J

**O que é esse projeto?**
Este projeto consiste em fazer um sistema seguro por meio do Classloader no Android. Para isso usaremos de um servidor e dos demais recursos em Java/JNI.
O classloader basicamente como diz o nome é um "carregador de classes". Desse modo podemos carregar um APK dinamicamente e utilizar de seus recursos de forma "online".

#### Esse sistema é seguro?

Bom, não existe um sistema que seja 100% seguro. Se voce pode, por exemplo encodar uma palavra para base64, voce pode decodifica-la. Isso vale para todos os tipos de encriptação. É claro que existem sistemas de encriptação mais fortes, mas em algum momento ficarão obsoletos.

Porem, eu posso afirmar que esse sistema é um pouco mais complexo de ser quebrado. As pessoas podem procurar as brechas e encontra-las, ainda mais em um open source. Eu não lançarei updates entao você mesmo terá que fazer proteções extras caso deseje. Eu deixarei algumas mais para o final.

#### Quais as diferenças entre esse e o seu projeto anterior?

Bom aqui vão algumas diferenças:

- Esse projeto usa alguns metodos JNI para melhor proteção...
- Uso de AES para encriptar a resposta do servidor
- A key para o AES é gerada somente quando o usuario é autenticado
- Confirmação da sessao do usuario, etc
- Compatibilidade com Android 12

#### Dicas de utilização:

Ter conhecimento em PHP, JAVA, JNI(C++) é fundamental. Aqui vai algumas explicações em relação aos metodos;

- Encrypt (Android Project)

     `Log.i("JNI", MainActivity.Encrypt("Sting to Encrypt"));`
	 aqui voce exibi a string encriptada no logcat

- Encrypt(PHP)

 `<?php include 'Utils.php`
 `echo EncryptByS4J("String to Encrypt)`


 - Decrypt (Android Project)

     `Log.i("JNI", MainActivity.Decrypt("Sting to Encrypt"));`
	 aqui voce exibi a string decriptada no logcat

- Stack

Voce pode armazenar uma variavei em sua JNI usando:
`MainActivity.Stack(int id, String str);`

e pode obtela por meio do:
`MainActivity.getStack(int id, bool isEncrypt);`

o bool isEncrypt serve para o metodo de Decrypt, ou seja se voce armazenar uma string que foi Encrypt voce pode decripta-la automaticamente;

#### Conceitos

**Limite de entrada** => Existe um limite de 128 bytes que voce pode enviar ao servidor. Por isso os usarios sao limitados a 16 caracteres, ja que outras coisas tambem sao enviadas;

**Limite de memoria** => O limite de memoria é uma configuração do servidor, isso varia de cada hospedagem ou de sua configuração.
Se voce fizer uma requisição ao servidor e ele nao apresentar "Server Error" ou nenhuma resposta essa pode ser a causa. Se seus Apks/libs forem muito grandes isso pode ocorrer.

**DDOS** => Eles podem fazer multiplas solicitações ao seu servidor. Voce pode resolver isso utilizando Cloudflare ou filtrando IPs ou User Agents..

**My Sql Inject** => Nessao versão foram corrigidos falhas relacionadas a isso. O DeviceID é obtido por meio do codigo nativo e os parametros sao passados por uma verificação no codigo JNI. Tambem é utilizado o `real_escape_string` do mysql no login.php

**Fechamento no App?** => Verifique o logcat, verifique as versoes de arquitetura das libs coincidem.

### Dicas

**Se seu android studio não esta compilando o codigo JNI:**

Voce pode usar o DAEMON que esta na pasta do projeto, basta trocar o diretorio dentro do arquivo make.bat e executar com a pasta JNI.

**Como eu uso implementações como Toast Customizado, Alertas com GIFS?**

Implemente isso na build.gradle do modulo app e do modulo loader e use a vontade.

**Posso eu usar isso no AIDE?**

Sim, desde que saiba o que esta fazendo

**Posso vender esse projeto?**

Nao acho que alguem compraria algo publico.

**Eu nao entendo nada do seu projeto, meus olhos doem**

Solução => Nao procure fazer uma redação em alemão se voce nao sabe nem falar alemão.
Do mesmo jeito nao procure usar esse projeto se voce nao sabe nem le-lo.

#### Updates

Esse projeto nao tera updates a nao ser sobre uma falha que exponha os dados.

## Eu preciso de mais segurança

Baixe o NP Manager que eu deixei no repositorio e procure pela função de **DexToC** ela é a unica que nao pode ser revertida. Utilize ela no App Principal ou no Loader, porem no Loader voce tera que carrega-la pelo servidor.

## Bugs Conhecidos

- No primeiro acesso do usuario ele diz algo sobre o UID, mas é apenas clicar novamente que vai;

- As vezes ele nao encontra o APK no cache;

- As vezes ele falha em colocar o "tempaeskey" do usuario (Mesmo caso do UID);

