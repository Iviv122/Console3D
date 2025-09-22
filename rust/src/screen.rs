pub struct Screen {
    pub width: usize,
    pub height: usize,
    pub data: Vec<u8>,
}
impl Screen {
    pub fn new(width: usize, height: usize) -> Screen {
        Screen {
            width: width,
            height: height,
            data: vec![32; width * height],
        }
    }
    pub fn reset(&mut self) -> () {
        self.data.clear();
        self.data.resize(self.width*self.height,32);
    }

    pub fn print(&self) -> () {
        for y in 0..=self.height-1{
            for x in 0..=self.width-1{
                print!("{c}", c = self.get(x, y) as char);
            }
            println!();
        }
    }

    pub fn get(&self, x: usize, y: usize) -> u8 {
        return self.data[self.width * y + x];
    }
    pub fn set(&mut self, x: usize, y: usize, data: u8) -> () {
        self.data[self.width * y + x] = data;
    }
}
