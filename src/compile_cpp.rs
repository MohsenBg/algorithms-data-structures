use std::process::{Command, Output};

#[allow(dead_code)]
pub enum Complier {
    GPlusPlus,
    Gcc,
    CPlusPlus,
}

#[allow(dead_code)]
pub enum OsType {
    Windows,
    Linux,
}

#[allow(dead_code)]
pub fn genrate_cli_compile(complier: Complier, path_source: &str, path_output: &str) -> String {
    let mut cli = String::new();
    let compiler = get_compiler(complier);
    cli.push_str(&compiler);
    cli.push_str("-o ");
    let file_type: String = get_output_file(path_output);

    cli.push_str(&file_type);
    cli.push(' ');
    cli.push_str(path_source);
    cli
}

#[allow(dead_code)]
pub fn get_output_file(path_output: &str) -> String {
    let mut output_file: String = String::from(path_output);
    let os_type = if cfg!(target_os = "windows") {
        OsType::Windows
    } else {
        OsType::Linux
    };
    match os_type {
        OsType::Windows => output_file.push_str(".exe"),
        OsType::Linux => output_file.push_str(".bin"),
    }
    output_file
}

#[allow(dead_code)]
fn get_compiler(compile_type: Complier) -> String {
    match compile_type {
        Complier::Gcc => return String::from("gcc "),
        Complier::GPlusPlus => return String::from("g++ "),
        Complier::CPlusPlus => return String::from("c++ "),
    }
}

#[allow(dead_code)]
pub fn run_commend(commend: &str) -> Output {
    if cfg!(target_os = "windows") {
        return Command::new("cmd").args(["/C", commend]).output().unwrap();
    } else {
        return Command::new("sh").arg("-c").arg(commend).output().unwrap();
    };
}
