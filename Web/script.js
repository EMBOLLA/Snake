const canvas = document.getElementById("gameCanvas");
const ctx = canvas.getContext("2d");
canvas.width = 400;
canvas.height = 400;

let score = 0;
let snake = [{x: 200, y: 200}];
let direction = {x: 0, y: 0};
let food = {x: Math.floor(Math.random() * 20) * 20, y: Math.floor(Math.random() * 20) * 20};

document.addEventListener("keydown", (event) => {
    if (event.key === "ArrowUp") direction = {x: 0, y: -20};
    if (event.key === "ArrowDown") direction = {x: 0, y: 20};
    if (event.key === "ArrowLeft") direction = {x: -20, y: 0};
    if (event.key === "ArrowRight") direction = {x: 20, y: 0};
});

function update() {
    let head = {x: snake[0].x + direction.x, y: snake[0].y + direction.y};

    if (head.x === food.x && head.y === food.y) {
        food = {x: Math.floor(Math.random() * 20) * 20, y: Math.floor(Math.random() * 20) * 20};
        score++; 
        document.getElementById("score").textContent = score;
    } else {
        snake.pop();
    }

    if (head.x < 0 || head.x >= canvas.width || head.y < 0 || head.y >= canvas.height) {
        alert("Game Over !");
        snake = [{x: 200, y: 200}];
        direction = {x: 0, y: 0};
    }

    snake.unshift(head);
}

function draw() {
    ctx.fillStyle = "black";
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    ctx.fillStyle = "red";
    ctx.fillRect(food.x, food.y, 20, 20);

    ctx.fillStyle = "green";
    snake.forEach(segment => ctx.fillRect(segment.x, segment.y, 20, 20));
}

function gameLoop() {
    update();
    draw();
    setTimeout(gameLoop, 180);
}

gameLoop();