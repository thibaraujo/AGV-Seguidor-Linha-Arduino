![capa vsl-ts](https://user-images.githubusercontent.com/86898996/164748915-a4197cbb-251f-4dd8-ae75-40d8c124fe93.png)
<h1>Automated Guided Vehicle (Seguidor de Linha) - Transportador de sementes</h1> 

> Status: Developed ✔️

## Descrição
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Atualmente, exige-se que o nível de atualização tanto da indústria quanto do profissional  prevaleça. A robótica, por exemplo,  tornou-se  comum  em  vários ambientes cotidianos, e com isso vários desafios surgiram, contribuindo para a rápida e constante evolução desses   sistemas   automatizados.   Dentre as   mudanças vivenciadas  por  esse  setor  tecnológico  destaca-se  o  desenvolvimento  dos  AGV’s (“Automatic Guided Vehicle” –Veículos  Guiados  Automaticamente).  Esse  tipo  de veículo move-se por trajetórias fixas, seguindo marcas contínuas, sendo encontrado em  indústrias,  armazéns  e  até  mesmo  hospitais.  Existem  muitos  modelos  de desenvolvimento  relacionados  a  AGV’s,  mas  ainda  assim  o  ambiente  de desenvolvimento para aplicações desses robôs continua muito ampla.</p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Dessa forma,  em  nosso  projeto  o  robô  VSL-TS  (Veículo  Seguidor  de  Linha –Transportador de Sementes) foi desenvolvido com o objetivo de auxiliar no transporte de sementes entre os setores de um Banco de Germoplasma – onde se armazenam, a partir da identificação e categorização, células germinativas de alguns seres vivos, sejam eles animais, sejam eles vegetais com o intuito de preservação, possuindo para isso  um  compartimento  para  o  posicionamento  de  tubos  de  ensaio  que  pode  ser adaptada conforme o local de aplicação.</p>

## Mecânica
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Tendo em vista a perspectiva de construir um veículo autônomo, analisou-se um  cenário  para  a  sua  aplicação,  sendo  escolhido  um  banco  de  germoplasma,  um local  com  a  finalidade  maior  de  preservar  os  materiais  genéticos  que  sejam  de interesse  para  o  homem,  por  meio  de  técnicas  que  permitam  maior  longevidade possível dos acessos armazenados. Os  bancos  de  germoplasma  são  os  principais  locais  para  disponibilizar  os recursos genéticos necessários para a obtenção de novas cultivares e/ou a melhoria das  existentes. Dessa  forma,  o design imaginado  visou  suprir  a  necessidade  de transporte de amostras biológicas entre os setores desse tipo de banco, como pode ser visto na imagem apresentada a seguir:</p>
<br>
<p>
<center>
 <img src="https://user-images.githubusercontent.com/86898996/164794333-fb95136e-3a5d-4c89-9833-2eb8b6a37c53.png">
</center>
</p>

## Eletrônica
<p>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A estrutura eletrônica principal do VSL-TS é composta basicamente por <a href="https://www.vishay.com/docs/83760/tcrt5000.pdf">módulos de sensores ópticos TCRT5000</a>, responsáveis por fazer a detecção da linha, <a href="https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf">sensores de distância ultrassônicos HC-SR04</a>, responsáveis pela detecção de obstáculos, <a href="https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf">Arduino UNO</a>, para o controle e processamento de dados, e o <a href="https://www.filipeflop.com/produto/driver-motor-ponte-h-l298n/">Driver Motor ponte-H L298N</a>, responsável por fazer o acionamento dos motores DC.
</p>
<br>
<img src="https://user-images.githubusercontent.com/86898996/164798833-40789bc1-d369-4f58-a18b-fcee09c77d56.png">

## Assistir ao vídeo de funcionamento do VSL-TS
<br>
<a href="https://youtu.be/_h_vWjWKDpU"><img src="https://user-images.githubusercontent.com/86898996/164801059-acf67a4f-ca62-4e5e-b78b-8947ab6e8c8d.jpeg"></a>

### Desenvolvedores
<p>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;O AGV VSL-TS foi desenvolvido no ano de 2019, por um grupo composto por: Luiz Otávio de Oliveira Domingos, Ryan Alves Mazzeu, Samuel Bárbara e Thiago Batista Araújo. Todos os integrantes do grupo tiveram interferência em todos os setores do projeto (mecânica, eletrônica e software).
</p>
<br>
<img src="https://user-images.githubusercontent.com/86898996/164801125-73f80b82-297d-4cb2-a41b-d2d0d207affd.jpeg">

<b>Redes Sociais dos envolvidos:</b>
<br>
Integrante  |  Rede Social
----------  |  -------------------------
Luiz Otávio | <a href="https://www.instagram.com/l_odomingos/"><img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white"></a>
Ryan        | <a href="https://www.facebook.com/RyanAlvesMazzeu"><img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white"></a>
Samuel      | <a href="https://www.instagram.com/samuelbarbado/"><img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white"></a>
Thiago      | <a href="https://www.instagram.com/thi_baraujo/"><img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white"></a>
