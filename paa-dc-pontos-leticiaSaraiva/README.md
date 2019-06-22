# Pontos mais próximos

## Descrição

Nesta atividade você deve se basear no código disponibilizado para implementar a funcionalidade de determinar, dado um conjunto de pontos no plano cartesiano, o par de pontos mais próximo.

A forma de cálculo da distância entre pontos deve ser a tradicional fórmula de distância euclidiana: 
$$
d(P, Q) = \sqrt{(P_x - Q_x)^2+(P_y - Q_y)^2}
$$
O algoritmo a ser implementado deve seguir a técnica de solução por *Divisão e Conquista*.

## O que alterar

- Você deve alterar os arquivos `aluno/closestpoints.cpp` e `aluno/closestpoints.hpp`para implementar o método `ClosestPointsSolver::solveFor` e adicionar quaisquer outros métodos auxiliares necessários. Este método é o que a interface irá disparar e consultar para destacar a sua solução.
- Você deve alterar o arquivo `aluno/aboutdialog.hpp` *apenas* para adicionar seu nome e email na porção destacada.

## Recursos

Este projeto utiliza o framework [Qt](http://www.qt.io/) para disponibilizar a visualização e a entrada dos pontos de forma gráfica. Sugiro usar a IDE Qt Creator para realizar a tarefa.

Da sua parte, é necessário apenas que você conheça a classe `QPointF` do Qt para realizar a tarefa. Entretanto, você só precisará usá-la, neste caso, para representação dos pontos no plano cartesiano, o que significa que é necessário basicamente saber como obter as coordenadas que os objetos dessa classe representam.

[A documentação desta classe você encontra aqui.](http://doc.qt.io/qt-5/qpointf.html)

Você também deverá usar o git para entregar a atividade. caso você não saiba usar a versão em texto, sugiro o uso da interface gráfica [GitKraken](https://www.gitkraken.com/), que possui executáveis para Windows, Linux e Mac em versões gratuitas.

## Uso da interface

A interface está implementada de forma simplificada, sem todos os recursos planejados, porém completamente funcional para o propósito do algoritmo.

Para inserir novos pontos na tela, clique no botão *Adicionar* e, logo após, clique no espaço de desenho em todas as posições onde deseja inserir um novo ponto. A própria interface evita que você insira pontos próximos demais.

Para chamar o algoritmo que você deve implementar, clique no botão *Resolver*. Os dois pontos que o seu método retornar serão destacados.

Para realizar um novo teste, é necessário clicar no botão *Novo*. Neste caso, todos os pontos anteriores serão apagados.

Ao clicar no botão *Sobre* aparecerá um diálogo com informações sobre a atividade e sobre você. Esses dados são extraídos do arquivo `aluno/aboutdialog.hpp`, portanto não esqueça de inseri-los.

## Informações

Este código faz parte das atividades práticas da disciplina "QXD0041 - Projeto e Análise de Algoritmos" do Campus da UFC em Quixadá. A não ser quando explicitamente determinado, todos os arquivos estão sob a licença GPLv3.

As implementações neste repositório foram fornecidas pelo Prof. Arthur Araruna ou pelos autores citados nos cabeçalhos dos arquivos.