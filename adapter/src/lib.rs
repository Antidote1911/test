use std::ffi::{CStr, CString};
use std::os::raw::c_char;
use std::ptr::null_mut;
use passgencore::{generate_password, getversion, Pool};

#[no_mangle]
pub extern "C" fn get_version() -> *mut c_char {
    rust_to_c_string(getversion().to_string())
}

#[no_mangle]
pub extern "C" fn get_random(length: u8,) -> *mut c_char {
    let pool: Pool = "0123456789".parse().unwrap();
    let password = generate_password(&pool, length as usize);
    rust_to_c_string(password)
}

#[no_mangle]
pub extern "C" fn get_shuffle(length: u8, pool: *mut c_char) -> *mut c_char {
    let test=c_to_rust_string(pool).unwrap();

    let pool: Pool = test.parse().unwrap();
    let password = generate_password(&pool, length as usize);
    rust_to_c_string(password.to_string())

}

fn rust_to_c_string(s: String) -> *mut c_char {
    CString::new(s).unwrap().into_raw()
}

fn c_to_rust_string(ptr: *mut c_char) -> Result<String, String> {
    let c_str: &CStr = unsafe { CStr::from_ptr(ptr) };
    let res = c_str
        .to_str()
        .map_err(|_| "Could not convert C string to Rust string".to_string())?
        .to_string();
    Ok(res)
}
