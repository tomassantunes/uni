function message(text) {
    let terminal = document.getElementById("terminal");
    terminal.innerHTML = text;
}

function clip(x, a, b) {
    return x < a ? a : (x > b ? b : x);
}

function main() {
    let i = 0;
    message("hello world");
}