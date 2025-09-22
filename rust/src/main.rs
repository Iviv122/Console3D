use core::time;
use std::{thread};

use crate::screen::Screen;

mod screen;
fn main() {
    let width: usize = 50;
    let height: usize = 50;
    let refresh_speed = 100;
    let mut it = 0.1;

    let mut screen: Screen = Screen::new(width, height);
    let delay =  time::Duration::from_millis(refresh_speed);

    loop {
        screen.reset();

        let x =(((screen.width / 2) as f64)+(f64::sin(it as f64)*10.)) as usize;
        let y =(((screen.height / 2) as f64)+(f64::cos(it as f64)*10.)) as usize;

        screen.set(x, y,'x' as u8);

        screen.print();
        thread::sleep(delay);
        it += 0.2;
    }
}
