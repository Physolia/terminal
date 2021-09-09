/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- ApplicationState.h

Abstract:
- TODO!
--*/
#pragma once

struct BaseApplicationState
{
    BaseApplicationState(std::filesystem::path path) noexcept;
    ~BaseApplicationState();

    // Methods
    void Reload() const noexcept;

    // General getters/setters
    winrt::hstring FilePath() const noexcept;

    virtual void FromJson(const Json::Value& root) const noexcept = 0;
    virtual Json::Value ToJson() const noexcept = 0;

protected:
    virtual void _write() const noexcept;
    void _read() const noexcept;

    std::filesystem::path _path;
    til::throttled_func_trailing<> _throttler;
};
