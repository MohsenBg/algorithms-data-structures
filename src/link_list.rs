#[allow(dead_code)]
static PATH_OUTPUT: &str = "src/Link_List/link_list_test";
#[allow(dead_code)]
static PATH_SOURCE: &str = "src/Link_List/link_list_test.cpp";

#[allow(dead_code)]
struct Flages<'a> {
    get_values: &'a str,
    begin: &'a str,
    end: &'a str,
    count: &'a str,
    reverce: &'a str,
    at_index: &'a str,
    find: &'a str,
    in_list: &'a str,
    remove: &'a str,
    insert: &'a str,
    change_value: &'a str,
}

#[allow(dead_code)]
static FLAGS: Flages = Flages {
    get_values: "--GV",
    begin: "--B",
    end: "--E",
    count: "--CO",
    change_value: "--CV",
    find: "--F",
    remove: "--RM",
    insert: "--IS",
    reverce: "--RV",
    in_list: "--IL",
    at_index: "--AI",
};

#[cfg(test)]
mod compile {
    use super::*;
    use crate::compile_cpp;

    #[test]
    fn link_list_compile_test() {
        let commend = compile_cpp::genrate_cli_compile(
            compile_cpp::Complier::GPlusPlus,
            PATH_SOURCE,
            PATH_OUTPUT,
        );

        println!("{commend}");
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
    use std::process::Output;

    struct Stup {
        input: Vec<i32>,
        commend: String,
    }

    #[derive(Debug)]
    struct _Result {
        input: Vec<i32>,
        flag_arg: Vec<i32>,
        output: Vec<i32>,
    }
    #[test]
    fn link_list_get_value() {
        let _result = run_without_flag_arg(FLAGS.get_values);
        assert_eq!(_result.input, _result.output);
    }

    #[test]
    fn link_list_begin() {
        let _result = run_without_flag_arg(FLAGS.get_values);
        assert_eq!(_result.input[0], _result.output[0]);
    }

    #[test]
    fn link_list_end() {
        let _result = run_without_flag_arg(FLAGS.end);
        println!("{:?}", _result);
        assert_eq!(_result.input.last(), _result.output.last());
    }

    #[test]
    fn link_list_count() {
        let _result = run_without_flag_arg(FLAGS.count);
        assert_eq!(_result.input.len(), _result.output[0] as usize);
    }

    #[test]
    fn link_list_reverce() {
        let mut _result = run_without_flag_arg(FLAGS.reverce);
        _result.input.reverse();
        assert_eq!(_result.input, _result.output);
    }

    #[test]
    fn link_list_at_index() {
        let _result = run_with_flag_arg(FLAGS.at_index);
        let mut correct_output: Vec<i32> = Vec::new();
        for number in _result.flag_arg {
            let value = _result.input[number as usize];
            correct_output.push(value);
        }
        assert_eq!(correct_output, _result.output);
    }

    #[test]
    fn link_list_find() {
        for _ in 0..10 {
            let _result = run_with_flag_arg(FLAGS.find);
            let mut correct_output: Vec<i32> = Vec::new();
            for number in _result.flag_arg {
                let index = find_postion_value(&_result.input, number);
                correct_output.push(index);
            }
            assert_eq!(correct_output, _result.output);
        }
    }

    #[test]
    fn link_list_in_list() {
        let _result = run_with_flag_arg(FLAGS.in_list);
        let mut correct_output: Vec<i32> = Vec::new();
        for value in _result.flag_arg {
            let in_list = is_value_in_list(&_result.input, value);
            correct_output.push(in_list);
        }
        assert_eq!(correct_output, _result.output);
    }

    #[test]
    fn link_list_remove() {
        let _result = run_with_flag_arg(FLAGS.remove);
        let mut correct_output: Vec<i32> = _result.input.clone();
        for index in _result.flag_arg.clone() {
            correct_output.remove(index as usize);
        }
        assert_eq!(
            correct_output, _result.output,
            "\nflag_arg:{:?}\ninput:{:?}\n",
            _result.flag_arg, _result.input
        );
    }

    #[test]
    fn link_list_insert() {
        let _result = run_with_flag_arg(FLAGS.insert);
        let mut correct_output: Vec<i32> = _result.input.clone();
        let mut index: usize = 0;

        while index < _result.flag_arg.len() {
            correct_output.insert(
                _result.flag_arg[index] as usize,
                _result.flag_arg[index + 1],
            );
            index += 2;
        }
        assert_eq!(
            correct_output, _result.output,
            "\nflag_arg:{:?}\ninput:{:?}\n",
            _result.flag_arg, _result.input
        );
    }

    #[test]
    fn link_list_change_value() {
        let _result = run_with_flag_arg(FLAGS.change_value);
        let mut correct_output: Vec<i32> = _result.input.clone();
        let mut index: usize = 0;

        while index < _result.flag_arg.len() {
            correct_output[_result.flag_arg[index] as usize] = _result.flag_arg[index + 1];
            index += 2;
        }
        assert_eq!(
            correct_output, _result.output,
            "\nflag_arg:{:?}\ninput:{:?}\n",
            _result.flag_arg, _result.input
        );
    }

    fn run_without_flag_arg(flag: &str) -> _Result {
        let stup = stup_base_test(flag);
        let output = compile_cpp::run_commend(&stup.commend);
        let output = test_file_executable(output);
        let str_output = format!("{:?}", String::from_utf8(output.stdout));
        let vec_output = convert_str_to_vec_int(&str_output);
        println!("{}", str_output);
        return _Result {
            input: stup.input,
            flag_arg: Vec::new(),
            output: vec_output,
        };
    }

    fn run_with_flag_arg(flag: &str) -> _Result {
        let stup = stup_base_test(flag);
        let flag_arg = genarte_rand_num_vec(10, 0, 10);
        let str_flag_arg = convert_vec_to_str(&flag_arg);
        let commend = format!("{} {}", stup.commend, str_flag_arg);
        let output = compile_cpp::run_commend(&commend);
        let output = test_file_executable(output);
        let str_output = format!("{:?}", String::from_utf8(output.stdout));
        let vec_output = convert_str_to_vec_int(&str_output);
        println!("{}", str_output);
        return _Result {
            input: stup.input,
            flag_arg,
            output: vec_output,
        };
    }

    fn stup_base_test(flag: &str) -> Stup {
        let file_type = compile_cpp::get_output_file(PATH_OUTPUT);
        let input = genarte_rand_num_vec(25, 0, 35); //(count,rang_start,range_end)
        let str_input = convert_vec_to_str(&input);
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

    fn genarte_rand_num_vec(cout: usize, begin: i32, last: i32) -> Vec<i32> {
        let mut rng = rand::thread_rng();
        let mut numbers: Vec<i32> = Vec::new();
        for _ in 0..cout {
            let rand_num = rng.gen_range(begin..=last);
            numbers.push(rand_num);
        }
        numbers
    }

    fn convert_vec_to_str(vec: &[i32]) -> String {
        let mut str: String = String::new();
        for num in vec {
            str.push_str(&format!("{} ", num.to_string()));
        }
        str
    }

    fn is_value_in_list(vec: &[i32], value: i32) -> i32 {
        for &number in vec {
            if number == value {
                return 1;
            }
        }
        return 0;
    }

    fn convert_str_to_vec_int(string: &str) -> Vec<i32> {
        let mut numbers: Vec<i32> = Vec::new();
        let mut str_num = String::new();
        let mut is_number: bool = false;
        for c in string.chars() {
            if c.is_numeric() || c == '-' {
                str_num.push(c);
                is_number = true;
            }

            if c == ' ' && is_number {
                is_number = false;
                let int_num: i32 = str_num.trim().parse().expect("expect number");
                numbers.push(int_num);
                str_num.clear();
            }
        }
        numbers
    }

    fn find_postion_value(vec: &[i32], value: i32) -> i32 {
        let mut index: usize = 0;
        while index < vec.len() {
            if vec[index] == value {
                return index as i32;
            }
            index += 1;
        }
        return -1;
    }
}
