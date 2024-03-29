#[allow(dead_code)]
static PATH_OUTPUT: &str = "src/Sorting/sorting_test";
#[allow(dead_code)]
static PATH_SOURCE: &str = "src/Sorting/sorting_test.cpp";

#[cfg(test)]
mod compile {
    use super::*;
    use crate::compile_cpp;

    #[test]
    fn sort_compile_test() {
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
mod sort {
    use super::*;
    use crate::compile_cpp;
    use rand::Rng;

    #[test]
    fn sort_bubble() {
        for _ in 0..20 {
            sort_run_test("--b");
        }
    }

    #[test]
    fn sort_insertion() {
        for _ in 0..20 {
            sort_run_test("--i");
        }
    }

    #[test]
    fn sort_selction() {
        for _ in 0..20 {
            sort_run_test("--s");
        }
    }

    #[test]
    fn sort_quick() {
        for _ in 0..20 {
            sort_run_test("--q");
        }
    }

    #[test]
    fn sort_marge() {
        for _ in 0..20 {
            sort_run_test("--m");
        }
    }

    fn sort_run_test(flag: &str) {
        let file_type = compile_cpp::get_output_file(PATH_OUTPUT);
        let mut inputs = gerate_random_vec_num();
        let mut str_inputs = String::new();

        for num in inputs.clone() {
            str_inputs += &format!("{} ", num);
        }

        str_inputs.push_str(flag);
        let commend = format!("{} {}", file_type, str_inputs);
        let output = compile_cpp::run_commend(&commend);
        let mut str_output = String::new();

        assert!(
            output.status.success(),
            "Run_Time_Error: {:#?}",
            String::from_utf8(output.stderr)
        );
        str_output.push_str(&format!("{:#?}", String::from_utf8(output.stdout)));

        let mut outputs: Vec<i32> = Vec::new();
        let mut is_number: bool = false;
        let mut num: String = String::new();
        for c in str_output.chars() {
            if c.is_numeric() || c == '-' {
                num.push(c);
                is_number = true;
            }
            if c == ' ' && is_number {
                is_number = false;
                let int_num: i32 = num.trim().parse().expect("expect number");
                outputs.push(int_num);
                num.clear();
            }
        }

        inputs.sort();

        assert_eq!(outputs, inputs);
    }
    fn gerate_random_vec_num() -> Vec<i32> {
        let mut inputs: Vec<i32> = Vec::new();
        let mut rng = rand::thread_rng();
        let count_num: usize = rng.gen_range(1..=10);
        for _ in 0..count_num {
            let random_num: i32 = rng.gen_range(-100..100);
            inputs.push(random_num);
        }
        inputs
    }
}
