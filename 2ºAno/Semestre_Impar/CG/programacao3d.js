function p3d(x, y, z) {
    return {x:x, y:y, z:z};
}

function dist(p, q) {
    
    let distance = Math.hypot(q.x - p.x, q.y - p.y, q.z - p.z);
    
    return distance;
}

// console.log(dist(p3d(1, 2, 3), p3d(0, 0, 0)));

function outer(u, v) {
    // x*uy*vz + y*uz*vx + z*ux*vy - x*uz*vy - y*ux*vz - z*uy*vx
    // == (uy*vz - uz*vy) * x + (uz*vx - ux*vz) * y + (ux*vy - uy*vx) * z 

    return p3d(
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.x,
        u.x * v.y - u.y * v.x 
    );
}

// console.log(outer(p3d(1, 0, 0), p3d(0, 1, 0)))

let X0 = p3d(50, 45, 1);
let Y0 = p3d(21, 12, 11);
let Z0 = p3d(2, 2, 2);

function average(xs) {
    if(xs.length === 0) return 0.0;

    let sum = 0;
    for(let xi of xs) sum += xi;

    return sum / xs.length;
}

function center(points) {
    return p3d(
        average(points.map(p => p.x)), // liga (soma) a componente x de cada ponto
        average(points.map(p => p.y)),
        average(points.map(p => p.z))
    )
}

// console.log(center([X0, Y0, Z0]));

function nearest(p, points) {
    if(points.length === 0) return null;

    let temp = 0;
    let closest = points[0];
    let result = dist(p, closest);
    
    for(let i = 1; i < points.length; i++) {
        temp = dist(p, points[i]);
        if(temp < result) {
            result = temp;
            closest = points[i];
        }
    }

    return {result, closest};
}

// console.log(nearest(p3d(6, 6, 6), [X0, Y0, Z0]));
// console.log(nearest(p3d(20, 17, 20), [X0, Y0, Z0]));
// console.log(nearest(p3d(1, 30, 4), [X0, Y0, Z0]));

function farthest(p, points) {
    if(points.length === 0) return null;
    
    let temp = 0;
    let farther = points[0];
    let result = dist(p, farther);

    for(let i = 0; i < points.length; i++) {
        temp = dist(p, points[i]);
        if(temp > result) {
            result = temp;
            farther = points[i];
        }
    }

    return {result, farther};
}

// console.log(farthest(p3d(6, 6, 6), [X0, Y0, Z0]))

function loneliest(points) {
    let c = center(points);

    let x = farthest(c, points);

    return x.farther;
}

// console.log(loneliest([X0, Y0, Z0]))

function centralest(points) {
    let c = center(points);

    let x = nearest(c, points);

    return x.closest;
}

// console.log(centralest([X0, Y0, Z0]))

function corner_tlb(points) {
    // const x = new Array();
    // const y = new Array();
    // const z = new Array();

    // for(let i = 0; i < points.length; i++) {
    //     x.push(points[i].x);
    //     y.push(points[i].y);
    //     z.push(points[i].z);
    // }

    // points.map(p => p.x)
    // points.map(p => p.y)
    // points.map(p => p.z)

    console.log(Math.min(points.map(p => p.x)))
    console.log(Math.max(points.map(p => p.y)))
    console.log(Math.min(points.map(p => p.z)))

    //return {x:Math.min(x), y:Math.max(y), z:Math.min(z)};
}

console.log(corner_tlb([X0, Y0, Z0]))