
let tmp = new Map();

function insert_map() {
    //tmp.set('color' , 'red');
    //tmp.set('reg', 'mh14');
    car = new Map();
    car.set('color', 'white');
    car.set('reg', 'tl14');
    tmp.set('tl14', car);
    return;
}

function get_car(reg) {
    return tmp.get(reg);
}

let get_value_in_map = async() => {
    car_ob = get_car('tl14');
    console.log(car_ob);
    console.log(car_ob.get('color'));
    console.log(car_ob.get('reg'));
}

insert_map();
get_value_in_map();
