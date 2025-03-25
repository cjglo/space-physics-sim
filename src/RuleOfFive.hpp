#pragma once
class RuleOfFive {
public:
    RuleOfFive() = default;
    RuleOfFive(const RuleOfFive& other) = delete;
    RuleOfFive& operator=(const RuleOfFive& other) = delete;
    RuleOfFive(RuleOfFive&& other) = delete;
    RuleOfFive& operator=(RuleOfFive&& other) = delete;
    ~RuleOfFive() = default;
};