#[unsafe(no_mangle)]
pub extern "C" fn __ciphAdd(left: u64, right: u64) -> u64 {
    left + right
}

#[unsafe(no_mangle)]
pub extern "C" fn __ciphEncrypt(data: *const u8, len: usize) -> i32 {
    (data as usize + len) as i32
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}

