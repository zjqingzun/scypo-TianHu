struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

fn main() {
    let mut rect = Rectangle {
        width: 30,
        height: 50,
    };
    
    let area = rect.area();
    println!("Diện tích: {}", area); // Print

    rect.width = 40; // Change a width
    println!("Diện tích mới: {}", rect.area()); // Print
}