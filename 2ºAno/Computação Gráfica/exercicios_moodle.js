function range(a, b) {
    const x = new Array();
    let index = 0;
    for(let i = a; i <= b; i++) {
        if(i % 2 === 1) {
            x[index] = i;
            index++;
        }
    }
    
    return x;
}

//console.log(range(0, 3));

function split(p, a) {
    const x = new Array();
    const array1 = new Array();
    const array2 = new Array();
    
    for(let i = 0; i < a.length; i++) {
        if(p(a[i])) {
            array1.push(a[i]);
        } else {
            array2.push(a[i]);
        }
    }

    x.push(array1, array2);
    return x;
}

//console.log(split(x => x >= 2, [1, 2, 3]));
//console.log(split(x => x % 2 === 0, [0, 2, 3]));

function range2(a, b) {
    const x = new Array();
    
    if(a === b) {
        x.push(a);
    } else if(a > b) { 
        return [];
    } else {
        for(let i = a; i <= b; i++) {
            x.push(i);
        }
    }

    return x;
}

//console.log(range2(0, 3));
//console.log(range2(7, 2));
//console.log(range2(0, 0));

function map(f, a) {
    const x = new Array();
    
    for(let i = 0; i < a.length; i++) {
        x.push(f(a[i]));
    }

    return x;
}

// console.log(map(x => 2*x, [1, 2, 3, 4]));
// console.log(map(x => x*x, [-2, -1, 0, 1, 2]));

function reverse(a) {
    const x = new Array();

    for(let i = a.length - 1; i >= 0; i--) {
        x.push(a[i]);
    }

    return x;
}

// console.log(reverse([1, 2, 3]));
// console.log(reverse([-2, -1, 0, 1, 2]));

function r(x) {
    return Math.round(x * 1000) / 1000;
}

function norm(a) {
    return Math.sqrt((a.x ** 2) + (a.y ** 2) + (a.z ** 2));
}

// console.log(r(norm({x: 1, y: 0, z: 0})))
// console.log(r(norm({x: 1, y: 1, z: 0})))

function count_pred(p, x) {
    let count = 0;
    for(let i = 0; i < x.length; i++) {
        if(p(x[i])) {
            count++;
        }
    }

    return count;
}

// console.log(count_pred(x => x > 0, [-2, 0, 2]))
// console.log(count_pred(x => x * x > 3, [-1, 0, 1]))

function r(x) {
    return Math.round(x * 100) / 100;
}
  
function clock_handles(h, m) {

    if (h < 0 || h > 11 || m < 0 || m > 59) {
        h = 0;
        m = 0;
    }       

    let alpha_h = Math.PI * (0.5 - h / 6.0);
    let hx = 1.0 * Math.cos(alpha_h);
    let hy = 1.0 * Math.sin(alpha_h);

    let alpha_m = Math.PI * (0.5 - m / 30.0);
    let mx = 0.7 * Math.cos(alpha_m);
    let my = 0.7 * Math.sin(alpha_m);

    return {hx: r(hx), hy: r(hy), mx: r(mx), my: r(my)};
}

// console.log(clock_handles(0, 15))
// console.log(clock_handles(3, 45))
// console.log(clock_handles(11, 60))

function is_leap(year) {
    if(year % 100 === 0 && year % 400 === 0) {
        return true;
    } else if(year % 4 === 0 && year % 100 !== 0) {
        return true;
    } else {
        return false;
    }
}

// console.log(is_leap(4))
// console.log(is_leap(16))
// console.log(is_leap(100))
// console.log(is_leap(2000))

function distance(p1, p2) {
    return Math.sqrt(((p1.x - p2.x) ** 2) + ((p1.y - p2.y) ** 2) );
}

// console.log(distance({x: 0, y: 0}, {x: 1, y: 0}));
// console.log(distance({x: 1, y: 1}, {x: 2, y: 2}));