# AbominationHunter

TRABALHO FINAL DE COMPUTAÇÃO GRÁFICA 2015

Grupo: 
- Amadeus Seilert
- Victor Costa
- Leo Sotto

O JOGO:

O nome do jogo, entre outras MUITAS coisas estarão sujeito a mudanças e sugestões;

Ideia: Jogo em terceira pessoa em modo sobrevivência. Um protagonista anda em um espaço que
em certos intervalos apareceriam inimigos aleatórios (esqueletos, monstros, fantasmas, etc)...
Conforme o personagem vai matando os inimigos ele vai ganhando pontos. Como o jogo é sobrevivência,
ele não tem fim, o tempo vai passando e os inimigos vão aparecendo em maior quantidade e mais fortes,
no entanto as habilidades do personagem podem ir se aprimorando, coletando armas mais potentes ou miscelancias
(colete a prova de balas, bonus de vida, bonus de dano, etc).

Camera: A camera inicialmente rastreia a posição do personagem, e com uma rotação fixa. Caso a professora cobre
que a camera tenha que ser masi dinâmcia podemos implementar para que ela olhe sempre para as costas do personagem

Protagonista: Ele possuira movimentos livres no plano xz, as teclas WASD formam a direção e a localização do ponteiro
do mouse formam o angulo de movimentação.
		Ele pode armazenar estado tais como:
			- Localização atual
			- Angulo da direção
			- Ação corrente (andando, atacando, morrendo, etc)
			- Pontos de vida
			- Arma corrente
			- Pontos de Jogo (Para marcar uma pontuação)
			- Pontos de energia (necessário para executar ações especiais)
			- velocidade de movimento

Armas: Entra na criatividade, elas só precisariam variar em relação a velocidade de disparo da animação e o quanto ela
inflinge de dano nos inimigos.
			
