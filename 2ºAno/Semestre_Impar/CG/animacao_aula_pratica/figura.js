function message(text) {
    let terminal = document.getElementById("terminal");
    terminal.innerHTML = text;
}

function begin_ref(dx, dy, sx, sy, a) {
    this.save();
    this.translate(dx, dy);
    this.scale(sx, sy);
    this.rotate(a);
}

function end_ref() {
    this.restore();
}

function draw_figure(f) {
    this.begin_ref(f.transform.dx, f.transform.dy, f.transform.sx, f.transform.sy, f.transform.a);
    
    let path = undefined;
    if(f.hasOwnProperty("shape")) {
        path = new Path2D();
        path.moveTo(f.shape[0].x, f.shape[0].y);
        for(let p of f.shape) {
            path.lineTo(p.x, p.y);
        }
    }

    if(f.hasOwnProperty("style")) {
        if(f.style.hasOwnProperty("fill")) {
            this.fillStyle = f.style.fill;
            this.fill(path);    
            if(path != undefined) this.fill(path);
        }

        if(f.style.hasOwnProperty("lineWidth")) {
            this.lineWidth = f.style.lineWidth;
        }
        
        if(f.style.hasOwnProperty("stroke")) {
            this.strokeStyle = f.style.stroke;
            this.stroke(path);
        }
    }
    
    if(f.hasOwnProperty("children")) {
        for(let child of f.children) this.draw_figure(child);
    }
    this.end_ref();
}

function animate(gc) {
    let model = init_model();
    
    let step = (ts) => {
        model = update(model);
        
        gc.render(model);
        requestAnimationFrame(step);
    }

    requestAnimationFrame(step);
}

function init_model() {
    return {
        age: 0,
        figures: [ 
        {
            shape: [{x: 0, y: 0}, {x: 1, y:0}, {x: 1, y: 1}, {x: 0, y: 1}],
            style: {fill: "crimson", stroke: "khaki", lineWidth: 0.05},
            transform: {
                dx: 0.25, dy: 0.25,
                sx: 0.125, sy: 0.125,
                a: 0},
            rot_vel: 0.01
        },
        {
            //shape: [{x: 0, y: 0}, {x: 1, y:0}, {x: 1, y: 1}, {x: 0, y: 1}],
            style: {fill: "crimson"},
            transform: {
                dx: 0.725, dy: 0.25,
                sx: 0.125, sy: 0.125,
                a: 0},
            children: [
                {
                    shape: [{x: 0, y: 0}, {x: 1, y: 1}, {x: 0, y: 1}],
                    style: {fill: "seagreen"},
                    transform: {
                        dx: 0.125, dy: 0.125,
                        sx: 0.725, sy: 0.725,
                        a: 0},
                }
            ],
            rot_vel: -0.01
        }
        ]
    };
}

function update(model) {
    model.age += 1;
    for(let f of model.figures) {
        f.transform.a += f.rot_vel;
    }
    return model;
}

function render(model) {
    message(`AGE: ${model.age}`);

    this.begin_ref(0, 0, this.canvas.width, this.canvas.height, 0);

    this.fillStyle = "SkyBlue";
    this.fillRect(0, 0, 1, 1);

    for(let f of model.figures) {
        this.draw_figure(f);
    }

    this.end_ref();
}

function main() {
    message("I'm alive!");

    let gc = document.getElementById("canvas").getContext("2d");

    gc.render = render;
    gc.begin_ref = begin_ref;
    gc.end_ref = end_ref;
    gc.draw_figure = draw_figure;

    gc.canvas.width = 512;
    gc.canvas.height =  512;

    animate(gc);
}