#[unsafe(no_mangle)]
pub extern "C" fn __ciphAdd(_left: u64, _right: u64) -> u64 {
    _left + _right
}

#[unsafe(no_mangle)]
pub extern "C" fn __ciphEncrypt(_data: *const u8, _len: usize) -> i32 {
    (_data as usize + _len) as i32
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn __itWorks() {
        let _result = __ciphAdd(2, 2);
        assert_eq!(_result, 4);
    }
}

