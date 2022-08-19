#[allow(dead_code)]
static PATH_OUTPUT: &str = "src/Hash_Table/hash_table_test";
#[allow(dead_code)]
static PATH_SOURCE: &str = "src/Hash_Table/hash_table_test.cpp";

#[allow(dead_code)]
struct Flages<'a> {
    get_keys: &'a str,
    is_key_exist: &'a str,
    get_node: &'a str,
    change_value: &'a str,
    get_values: &'a str,
}

#[allow(dead_code)]
static FLAGS: Flages = Flages {
    get_values: "--GV",
    get_keys: "--GK",
    get_node: "--GN",
    is_key_exist: "--IKE",
    change_value: "--CV",
};

#[cfg(test)]
mod compile {
    use super::*;
    use crate::compile_cpp;

    #[test]
    fn hash_table_compile_test() {
        let commend = compile_cpp::genrate_cli_compile(
            compile_cpp::Complier::GPlusPlus,
            PATH_SOURCE,
            PATH_OUTPUT,
        );

        let output = compile_cpp::run_commend(&commend);
        assert!(
            output.status.success(),
            "Compiler_Error: {:#?}",
            String::from_utf8(output.stderr)
        );
    }
}

#[cfg(test)]
mod link_list {
    use super::*;
    use crate::compile_cpp;
    use rand::Rng;
    use std::{collections::HashMap, fmt::Display, process::Output};

    struct Stup<T> {
        input: Vec<T>,
        commend: String,
    }
    #[derive(Debug)]
    struct _Result<T, U, Z> {
        input: Vec<T>,
        flag_arg: Vec<U>,
        output: Vec<Z>,
    }

    #[test]
    fn hash_table_get_keys() {
        let _result = run_without_flag_arg(FLAGS.get_keys);
        let mut correct_output: Vec<String> = Vec::new();
        let mut index: usize = 0;
        while index < _result.input.len() {
            correct_output.push(_result.input[index].clone());
            index += 2;
        }
        assert_eq!(
            correct_output, _result.output,
            "\nflag_arg:{:?}\ninput:{:?}\n",
            _result.flag_arg, _result.input
        );
    }

    #[test]
    fn hash_table_get_value() {
        let _result = run_without_flag_arg(FLAGS.get_values);
        let mut correct_output: Vec<String> = Vec::new();
        let mut index: usize = 1;
        while index < _result.input.len() {
            correct_output.push(_result.input[index].clone());
            index += 2;
        }
        assert_eq!(
            correct_output, _result.output,
            "\nflag_arg:{:?}\ninput:{:?}\n",
            _result.flag_arg, _result.input
        );
    }

    #[test]
    fn hash_table_get_node() {
        let _result = run_with_flag_arg(FLAGS.get_node);
        let mut correct_output: Vec<String> = Vec::new();
        let hash_map = convert_vec_to_hash_map(&_result.input);

        for arg in _result.flag_arg.clone() {
            if hash_map.contains_key(&arg) {
                correct_output.push(hash_map[&arg].clone());
            }
        }

        assert_eq!(
            correct_output, _result.output,
            "\nflag_arg:{:?}\ninput:{:?}\n",
            _result.flag_arg, _result.input
        );
    }

    #[test]
    fn hash_table_is_key_exist() {
        let _result = run_with_flag_arg(FLAGS.is_key_exist);
        let mut correct_output: Vec<String> = Vec::new();
        let hash_map = convert_vec_to_hash_map(&_result.input);

        for arg in _result.flag_arg.clone() {
            if hash_map.contains_key(&arg) {
                correct_output.push(String::from("1"));
            } else {
                correct_output.push(String::from("0"));
            }
        }

        assert_eq!(
            correct_output, _result.output,
            "\nflag_arg:{:?}\ninput:{:?}\n",
            _result.flag_arg, _result.input
        );
    }

    #[test]
    fn hash_table_change_value() {
        let _result = run_with_flag_arg(FLAGS.change_value);
        let mut correct_output: Vec<String> = Vec::new();
        let mut hash_map = convert_vec_to_hash_map(&_result.input);

        for index in (0.._result.flag_arg.len()).step_by(2) {
            let arg1 = _result.flag_arg[index].clone();
            let arg2 = _result.flag_arg[index + 1].clone();
            if hash_map.contains_key(&arg1) {
                hash_map.insert(arg1, arg2);
            }
        }

        for key in _result.input.clone() {
            if hash_map.contains_key(&key) {
                correct_output.push(hash_map[&key].clone());
            }
        }

        assert_eq!(
            correct_output, _result.output,
            "\nflag_arg:{:?}\ninput:{:?}\n",
            _result.flag_arg, _result.input
        );
    }

    fn run_without_flag_arg(flag: &str) -> _Result<String, String, String> {
        let stup = stup_base_test(flag);
        let output = compile_cpp::run_commend(&stup.commend);
        let output = test_file_executable(output);
        let str_output = format!("{:?}", String::from_utf8(output.stdout));
        let vec_output = convert_str_to_vec(&str_output);

        return _Result {
            input: stup.input,
            flag_arg: Vec::new(),
            output: vec_output,
        };
    }

    fn run_with_flag_arg(flag: &str) -> _Result<String, String, String> {
        let stup = stup_base_test(flag);
        let flag_arg = select_rand_element_vec(10, &stup.input);
        let str_flag_arg = convert_vec_to_str(&flag_arg);
        let commend = format!("{} {}", stup.commend, str_flag_arg);
        println!("\ncommend: {commend}\n");
        let output = compile_cpp::run_commend(&commend);
        let output = test_file_executable(output);
        let str_output = format!("{:?}", String::from_utf8(output.stdout));
        let vec_output = convert_str_to_vec(&str_output);
        return _Result {
            input: stup.input,
            flag_arg,
            output: vec_output,
        };
    }

    fn stup_base_test(flag: &str) -> Stup<String> {
        let file_type = compile_cpp::get_output_file(PATH_OUTPUT);
        let input = genarte_rand_string(10); //(count,rang_start,range_end)
        let str_input: String = convert_vec_to_str(&input);
        let commend = format!("{} {} {}", file_type, str_input, flag);
        return Stup { input, commend };
    }

    fn test_file_executable(output: Output) -> Output {
        // test file run succusfully
        assert!(
            output.status.success(),
            "Run_Time_Error: {:#?}",
            String::from_utf8(output.stderr)
        );
        return output;
    }

    fn genarte_rand_string(cout: usize) -> Vec<String> {
        let alphabet = [
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
            'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        ];
        let mut rng = rand::thread_rng();
        let mut strings: Vec<String> = Vec::new();
        for _ in 0..cout {
            let mut str = String::new();
            for _ in 0..5 {
                let rand_index = rng.gen_range(0..alphabet.len());
                let rand_char = alphabet[rand_index];
                str.push(rand_char);
            }
            strings.push(str.clone());
        }
        strings
    }

    fn convert_vec_to_str<T: Display>(vec: &[T]) -> String {
        let mut str: String = String::new();
        for item in vec {
            str.push_str(&format!("{} ", item));
        }
        str
    }

    fn convert_str_to_vec(str: &str) -> Vec<String> {
        let mut words: Vec<String> = Vec::new();
        let mut word = String::new();
        let mut is_char = false;

        let _str = str.clone().replace("Ok", "");
        for c in _str.chars() {
            if c.is_alphanumeric() {
                word.push(c);
                is_char = true;
            }
            if c == ' ' && is_char {
                is_char = false;
                words.push(word.clone());
                word.clear();
            }
        }
        words
    }

    fn select_rand_element_vec(count: usize, vec: &[String]) -> Vec<String> {
        let mut rand_vec: Vec<String> = Vec::new();
        let mut copy_main_vec = vec.clone().to_vec();
        let mut rng = rand::thread_rng();
        for _ in 0..count {
            let rand_index: usize = rng.gen_range(0..copy_main_vec.len());
            let item = copy_main_vec[rand_index].clone();
            copy_main_vec.remove(rand_index);
            rand_vec.push(item);
        }

        rand_vec
    }

    fn convert_vec_to_hash_map(vec: &[String]) -> HashMap<String, String> {
        let mut hash_map: HashMap<String, String> = HashMap::new();
        for index in (0..vec.len()).step_by(2) {
            hash_map.insert(vec[index].clone(), vec[index + 1].clone());
        }
        hash_map
    }
}
